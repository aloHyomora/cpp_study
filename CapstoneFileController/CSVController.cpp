#include "CSVController.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
#include <cwchar>
#include <iostream>

// ���� �Լ����� �͸� ���ӽ����̽��� �����մϴ�.
namespace {
    // CSV �� ���� �޸� �������� �и�
    std::vector<std::wstring> splitCSVLine(const std::wstring& line) {
        std::vector<std::wstring> cells;
        std::wstringstream ss(line);
        std::wstring cell;
        while (std::getline(ss, cell, L',')) {
            cells.push_back(cell);
        }
        return cells;
    }

    // CSV ������ 2���� ����(�ࡿ��)�� �б�
    std::vector<std::vector<std::wstring>> readCSV(const std::wstring& filePath) {
        std::vector<std::vector<std::wstring>> data;
        std::wifstream file(filePath);
        file.imbue(std::locale("en_US.UTF-8")); // UTF-8 ������ ����
        std::wstring line;

        bool isFirstLine = true; // ù ��(���) ���ÿ� �÷���
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            if (isFirstLine) {
                isFirstLine = false;
                continue; // ù ��(���)�� ����
            }
            data.push_back(splitCSVLine(line));
        }
        return data;
    }


    // 2���� ���� �����͸� CSV ���Ϸ� ����
    void writeCSV(const std::wstring& filePath, const std::vector<std::vector<std::wstring>>& data) {
        std::wofstream out(filePath);
        out.imbue(std::locale("")); // ������ ���� (�ʿ��)
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                out << row[i];
                if (i != row.size() - 1)
                    out << L",";
            }
            out << L"\n";
        }
    }

    // "HH:MM:SS:ms" ������ ���ڿ��� �и��� ������ ������ ��ȯ
    long timeStrToMs(const std::wstring& timeStr) {
        int h = 0, m = 0, s = 0, ms = 0;
        swscanf_s(timeStr.c_str(), L"%d:%d:%d:%d", &h, &m, &s, &ms);
        return ((h * 3600 + m * 60 + s) * 1000 + ms);
    }

    // ��� ������ ������ ����ü
    struct Block {
        int startRow;   // _combined.csv���� ����� ���� �� �ε���
        int endRow;     // ����� ������ �� �ε���
        long startTime; // ����� ���� �ð� (�и���)
        long endTime;   // ����� �� �ð� (�и���)
    };

    // _combined.csv�� ���� ��(timeColIndex, ���⼭�� 3�� �ε���)�� �ִ� �ð� �����͸� �������,
    // ���ӵ� �� ������ �ð� ���̰� gapThreshold �̻��̸� �� ������� �Ǵ�
    std::vector<Block> detectBlocks(const std::vector<std::vector<std::wstring>>& data, int timeColIndex, long gapThreshold) {
        std::vector<Block> blocks;
        if (data.empty()) return blocks;

        int n = static_cast<int>(data.size());
        int blockStart = 0;
        for (int i = 1; i < n; i++) {
            if (data[i].size() <= (size_t)timeColIndex || data[i - 1].size() <= (size_t)timeColIndex)
                continue;
            long prevTime = timeStrToMs(data[i - 1][timeColIndex]);
            long currentTime = timeStrToMs(data[i][timeColIndex]);
            if (currentTime - prevTime > gapThreshold) {
                Block blk;
                blk.startRow = blockStart;
                blk.endRow = i - 1;
                blk.startTime = timeStrToMs(data[blockStart][timeColIndex]);
                blk.endTime = timeStrToMs(data[i - 1][timeColIndex]);
                blocks.push_back(blk);
                blockStart = i;
            }
        }
        // ������ ��� �߰�
        if (blockStart < n) {
            Block blk;
            blk.startRow = blockStart;
            blk.endRow = n - 1;
            blk.startTime = timeStrToMs(data[blockStart][timeColIndex]);
            blk.endTime = timeStrToMs(data[n - 1][timeColIndex]);
            blocks.push_back(blk);
        }
        return blocks;
    }

    // �ٸ� CSV ���Ͽ���, ������ �ð� ���� [blockStartTime, blockEndTime] ���� �ش��ϴ� ����� ����
    // otherTimeColIndex: �ٸ� CSV ���Ͽ��� �ð� �����Ͱ� ��ġ�� �� (���⼭�� 2�� �ε���)
    std::vector<std::vector<std::wstring>> extractMatchingRows(const std::vector<std::vector<std::wstring>>& data,
        long blockStartTime, long blockEndTime,
        int otherTimeColIndex) {
        std::vector<std::vector<std::wstring>> matching;
        for (const auto& row : data) {
            if (row.size() <= (size_t)otherTimeColIndex)
                continue;
            long t = timeStrToMs(row[otherTimeColIndex]);
            if (t >= blockStartTime && t <= blockEndTime) {
                matching.push_back(row);
            }
        }
        return matching;
    }

} // end anonymous namespace

// CSVController::mergeGroupFilesAdvanced ����
// gapThreshold: ��� ��� �Ǵ� �Ӱ�ġ (�и���, ���⼭�� ���� ��� 1000ms)
// blockDuration: �� ��ϸ��� ���� �ð� ���� (��� ���� �ð����� blockDuration(ms)����, ��: 4500ms)
void CSVController::mergeGroupFilesAdvanced(const std::wstring& combinedPath,
    const std::vector<std::wstring>& otherPaths,
    const std::wstring& outputPath) {
    // 1. combined.csv ���� �б� (�ð� �����ʹ� 4��, �ε��� 3)
    auto combinedData = readCSV(combinedPath);
    if (combinedData.empty()) {
        std::wcerr << L"Combined ������ ���� ���߽��ϴ�.\n";
        return;
    }

    // 2. �ٸ� CSV ���ϵ��� �о����
    std::vector< std::vector<std::vector<std::wstring>> > otherDataFiles;
    for (const auto& path : otherPaths) {
        otherDataFiles.push_back(readCSV(path));
    }

    // 3. combined.csv�� ��� ���� (���� �� ������ �ð� ���̰� gapThreshold �̻��̸� �� ���)
    // ���⼭ gapThreshold�� 1000ms (�ʿ信 ���� ����)
    int combinedTimeColIndex = 3;
    long gapThreshold = 1000;
    long blockDuration = 4500; // �� ��Ͽ� ���� 4.5�� ���� ���
    auto blocks = detectBlocks(combinedData, combinedTimeColIndex, gapThreshold);

    // 4. ���� ����� combinedData�� ������� ������Ʈ
    // �� ��� ���� �� �࿡ ����, �ٸ� CSV ������ �����͸� �����ʿ� �� ������ �߰�
    // �� ���� �ٸ��� ������ �κ��� �� ���ڿ�("")�� ä��
    std::vector<std::vector<std::wstring>> mergedData = combinedData; // �ʱ⿡�� combined ������ �״��

    for (const auto& blk : blocks) {
        // ����� �ð� ����: ���� �ð����� ���� �ð� + blockDuration
        long blockStartTime = timeStrToMs(combinedData[blk.startRow][combinedTimeColIndex]);
        long blockEndTime = blockStartTime + blockDuration;

        // �� �ٸ� CSV ���Ϻ���, �ش� �ð� ���� ���� ����� ����
        std::vector< std::vector<std::vector<std::wstring>> > matchingDataPerFile;
        for (const auto& otherData : otherDataFiles) {
            int otherTimeColIndex = 2; // �ٸ� ���Ͽ����� 3�� (�ε��� 2)
            auto matchingRows = extractMatchingRows(otherData, blockStartTime, blockEndTime, otherTimeColIndex);
            matchingDataPerFile.push_back(matchingRows);
        }

        // ��� ���� �� ����
        int blockRowCount = blk.endRow - blk.startRow + 1;

        // �� �ٸ� CSV ���Ϻ���, �߰��� ���� ������ Ȯ�� (ù ���� �� ���� �Ǵ�)
        std::vector<int> otherFileColCounts;
        for (const auto& matchRows : matchingDataPerFile) {
            int colCount = (!matchRows.empty()) ? static_cast<int>(matchRows[0].size()) : 0;
            otherFileColCounts.push_back(colCount);
        }

        // ��� �� �� �࿡ ����, �� �ٸ� CSV ������ ��Ī �����͸� ������� �����ʿ� �߰�
        for (int i = 0; i < blockRowCount; i++) {
            int currentRow = blk.startRow + i;
            for (size_t fileIdx = 0; fileIdx < matchingDataPerFile.size(); fileIdx++) {
                const auto& matchRows = matchingDataPerFile[fileIdx];
                int expectedCols = otherFileColCounts[fileIdx];
                if (i < static_cast<int>(matchRows.size())) {
                    // �ش� ���Ͽ� ��Ī �����Ͱ� ������ �� ���� ��� ���� �߰�
                    for (const auto& cell : matchRows[i]) {
                        mergedData[currentRow].push_back(cell);
                    }
                }
                else {
                    // ��Ī �����Ͱ� ������ ���, �� ���ڿ��� ���� ä��
                    for (int c = 0; c < expectedCols; c++) {
                        mergedData[currentRow].push_back(L"");
                    }
                }
            }
        }
    }

    // 5. ���� ���յ� �����͸� outputPath�� ����
    writeCSV(outputPath, mergedData);
    std::wcout << L"Merging complete. Output saved to: " << outputPath << std::endl;
}
