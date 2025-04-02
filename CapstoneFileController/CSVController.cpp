#include "CSVController.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
#include <cwchar>
#include <iostream>

// 헬퍼 함수들을 익명 네임스페이스에 정의합니다.
namespace {
    // CSV 한 줄을 콤마 기준으로 분리
    std::vector<std::wstring> splitCSVLine(const std::wstring& line) {
        std::vector<std::wstring> cells;
        std::wstringstream ss(line);
        std::wstring cell;
        while (std::getline(ss, cell, L',')) {
            cells.push_back(cell);
        }
        return cells;
    }

    // CSV 파일을 2차원 벡터(행×열)로 읽기
    std::vector<std::vector<std::wstring>> readCSV(const std::wstring& filePath) {
        std::vector<std::vector<std::wstring>> data;
        std::wifstream file(filePath);
        file.imbue(std::locale("en_US.UTF-8")); // UTF-8 로케일 설정
        std::wstring line;

        bool isFirstLine = true; // 첫 줄(헤더) 무시용 플래그
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            if (isFirstLine) {
                isFirstLine = false;
                continue; // 첫 줄(헤더)는 무시
            }
            data.push_back(splitCSVLine(line));
        }
        return data;
    }


    // 2차원 벡터 데이터를 CSV 파일로 쓰기
    void writeCSV(const std::wstring& filePath, const std::vector<std::vector<std::wstring>>& data) {
        std::wofstream out(filePath);
        out.imbue(std::locale("")); // 로케일 설정 (필요시)
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                out << row[i];
                if (i != row.size() - 1)
                    out << L",";
            }
            out << L"\n";
        }
    }

    // "HH:MM:SS:ms" 형식의 문자열을 밀리초 단위의 정수로 변환
    long timeStrToMs(const std::wstring& timeStr) {
        int h = 0, m = 0, s = 0, ms = 0;
        swscanf_s(timeStr.c_str(), L"%d:%d:%d:%d", &h, &m, &s, &ms);
        return ((h * 3600 + m * 60 + s) * 1000 + ms);
    }

    // 블록 정보를 저장할 구조체
    struct Block {
        int startRow;   // _combined.csv에서 블록의 시작 행 인덱스
        int endRow;     // 블록의 마지막 행 인덱스
        long startTime; // 블록의 시작 시간 (밀리초)
        long endTime;   // 블록의 끝 시간 (밀리초)
    };

    // _combined.csv의 지정 열(timeColIndex, 여기서는 3번 인덱스)에 있는 시간 데이터를 기반으로,
    // 연속된 행 사이의 시간 차이가 gapThreshold 이상이면 새 블록으로 판단
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
        // 마지막 블록 추가
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

    // 다른 CSV 파일에서, 지정한 시간 범위 [blockStartTime, blockEndTime] 내에 해당하는 행들을 추출
    // otherTimeColIndex: 다른 CSV 파일에서 시간 데이터가 위치한 열 (여기서는 2번 인덱스)
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

// CSVController::mergeGroupFilesAdvanced 구현
// gapThreshold: 블록 경계 판단 임계치 (밀리초, 여기서는 예를 들어 1000ms)
// blockDuration: 각 블록마다 사용될 시간 범위 (블록 시작 시간부터 blockDuration(ms)까지, 예: 4500ms)
void CSVController::mergeGroupFilesAdvanced(const std::wstring& combinedPath,
    const std::vector<std::wstring>& otherPaths,
    const std::wstring& outputPath) {
    // 1. combined.csv 파일 읽기 (시간 데이터는 4열, 인덱스 3)
    auto combinedData = readCSV(combinedPath);
    if (combinedData.empty()) {
        std::wcerr << L"Combined 파일을 읽지 못했습니다.\n";
        return;
    }

    // 2. 다른 CSV 파일들을 읽어들임
    std::vector< std::vector<std::vector<std::wstring>> > otherDataFiles;
    for (const auto& path : otherPaths) {
        otherDataFiles.push_back(readCSV(path));
    }

    // 3. combined.csv의 블록 감지 (연속 행 사이의 시간 차이가 gapThreshold 이상이면 새 블록)
    // 여기서 gapThreshold는 1000ms (필요에 따라 조정)
    int combinedTimeColIndex = 3;
    long gapThreshold = 1000;
    long blockDuration = 4500; // 각 블록에 대해 4.5초 범위 사용
    auto blocks = detectBlocks(combinedData, combinedTimeColIndex, gapThreshold);

    // 4. 병합 결과를 combinedData를 기반으로 업데이트
    // 각 블록 내의 각 행에 대해, 다른 CSV 파일의 데이터를 오른쪽에 열 단위로 추가
    // 행 수가 다르면 부족한 부분은 빈 문자열("")로 채움
    std::vector<std::vector<std::wstring>> mergedData = combinedData; // 초기에는 combined 데이터 그대로

    for (const auto& blk : blocks) {
        // 블록의 시간 범위: 시작 시간부터 시작 시간 + blockDuration
        long blockStartTime = timeStrToMs(combinedData[blk.startRow][combinedTimeColIndex]);
        long blockEndTime = blockStartTime + blockDuration;

        // 각 다른 CSV 파일별로, 해당 시간 범위 내의 행들을 추출
        std::vector< std::vector<std::vector<std::wstring>> > matchingDataPerFile;
        for (const auto& otherData : otherDataFiles) {
            int otherTimeColIndex = 2; // 다른 파일에서는 3열 (인덱스 2)
            auto matchingRows = extractMatchingRows(otherData, blockStartTime, blockEndTime, otherTimeColIndex);
            matchingDataPerFile.push_back(matchingRows);
        }

        // 블록 내의 행 개수
        int blockRowCount = blk.endRow - blk.startRow + 1;

        // 각 다른 CSV 파일별로, 추가할 열의 개수를 확인 (첫 행의 열 수로 판단)
        std::vector<int> otherFileColCounts;
        for (const auto& matchRows : matchingDataPerFile) {
            int colCount = (!matchRows.empty()) ? static_cast<int>(matchRows[0].size()) : 0;
            otherFileColCounts.push_back(colCount);
        }

        // 블록 내 각 행에 대해, 각 다른 CSV 파일의 매칭 데이터를 순서대로 오른쪽에 추가
        for (int i = 0; i < blockRowCount; i++) {
            int currentRow = blk.startRow + i;
            for (size_t fileIdx = 0; fileIdx < matchingDataPerFile.size(); fileIdx++) {
                const auto& matchRows = matchingDataPerFile[fileIdx];
                int expectedCols = otherFileColCounts[fileIdx];
                if (i < static_cast<int>(matchRows.size())) {
                    // 해당 파일에 매칭 데이터가 있으면 그 행의 모든 셀을 추가
                    for (const auto& cell : matchRows[i]) {
                        mergedData[currentRow].push_back(cell);
                    }
                }
                else {
                    // 매칭 데이터가 부족한 경우, 빈 문자열로 열을 채움
                    for (int c = 0; c < expectedCols; c++) {
                        mergedData[currentRow].push_back(L"");
                    }
                }
            }
        }
    }

    // 5. 최종 병합된 데이터를 outputPath로 저장
    writeCSV(outputPath, mergedData);
    std::wcout << L"Merging complete. Output saved to: " << outputPath << std::endl;
}
