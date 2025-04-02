#include "FileLoader.h"
#include "CSVController.h" // �߰�: CSV ���� ��� ����� ���� ��� ����
#include <windows.h>
#include <commdlg.h>
#include <unordered_map>
#include <fstream>
#include <memory>

std::vector<FileLoader::FileInfo> FileLoader::OpenFileDialog() {
    std::vector<FileLoader::FileInfo> fileInfos;
    OPENFILENAME ofn;
    std::unique_ptr<WCHAR[]> szFile(new WCHAR[260 * MAX_FILES]()); // �ִ� ���� ���� �°� ���� ���۸� �Ҵ��մϴ�.

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;
    ofn.lpstrFile = szFile.get();
    ofn.nMaxFile = 260 * MAX_FILES;
    ofn.lpstrFilter = L"CSV Files\0*.csv\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_EXPLORER;

    if (GetOpenFileName(&ofn) == TRUE) {
        WCHAR* p = ofn.lpstrFile;
        std::wstring directory = p;
        p += directory.length() + 1;

        while (*p) {
            std::wstring fileName = p;
            std::wstring filePath = directory + L"\\" + fileName;
            fileInfos.push_back({ fileName, filePath });
            p += wcslen(p) + 1;
        }

        // ���� ���� ������ ���
        if (fileInfos.empty()) {
            std::wstring fileName = directory.substr(directory.find_last_of(L"\\") + 1);
            fileInfos.push_back({ fileName, directory });
        }
    }

    return fileInfos;
}

void FileLoader::GroupAndCopyFiles(const std::vector<FileLoader::FileInfo>& fileInfos) {
    std::unordered_map<std::wstring, std::vector<FileLoader::FileInfo>> groups;

    // ���� �̸����� �׷��� �����ϴ�.
    for (const auto& fileInfo : fileInfos) {
        size_t pos = fileInfo.fileName.find(L"_", fileInfo.fileName.find(L"_") + 1);
        if (pos != std::wstring::npos) {
            std::wstring groupName = fileInfo.fileName.substr(0, pos);
            groups[groupName].push_back(fileInfo);
        }
    }

    // �׷캰�� ������ ó���մϴ�.
    for (const auto& group : groups) {
        std::wstring combinedFilePath;       // _combined.csv ���� ���
        std::vector<std::wstring> otherFilePaths;  // _Unity.csv ���� �ٸ� CSV ���� ���

        // �׷� �� ��� ������ Ȯ���մϴ�.
        for (const auto& fileInfo : group.second) {
            if (fileInfo.fileName.find(L"_Unity.csv") != std::wstring::npos) {
                // _Unity.csv�� _combined.csv�� ����
                combinedFilePath = fileInfo.filePath.substr(0, fileInfo.filePath.find_last_of(L"\\"))
                    + L"\\" + group.first + L"_combined.csv";

                std::ifstream src(fileInfo.filePath, std::ios::binary);
                std::ofstream dst(combinedFilePath, std::ios::binary);
                dst << src.rdbuf();
            }
            else {
                // _Unity.csv�� �ƴ� ������ ���� ��θ� ����
                otherFilePaths.push_back(fileInfo.filePath);
            }
        }

        // �׷쿡 _combined.csv�� �ٸ� CSV ���ϵ��� ��� ������ ��� ���� ����
        if (!combinedFilePath.empty() && !otherFilePaths.empty()) {
            // �⺻ ���丮�� �׷��� ù ��° ���� ��ο��� ���� (��� ���� ��� ������ ����)
            std::wstring baseDirectory = group.second.front().filePath.substr(0, group.second.front().filePath.find_last_of(L"\\"));
            std::wstring outputPath = baseDirectory + L"\\" + group.first + L"_merged.csv";

            // CSVController�� ���� ��� ȣ��
            // (CSVController::mergeGroupFilesAdvanced�� combinedPath, otherPaths, outputPath�� ���ڷ� �޾� ���յ� ������ ����)
            CSVController::mergeGroupFilesAdvanced(combinedFilePath, otherFilePaths, outputPath);
        }
    }
}
