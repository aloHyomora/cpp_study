#include "FileLoader.h"
#include "CSVController.h" // 추가: CSV 병합 기능 사용을 위한 헤더 포함
#include <windows.h>
#include <commdlg.h>
#include <unordered_map>
#include <fstream>
#include <memory>

std::vector<FileLoader::FileInfo> FileLoader::OpenFileDialog() {
    std::vector<FileLoader::FileInfo> fileInfos;
    OPENFILENAME ofn;
    std::unique_ptr<WCHAR[]> szFile(new WCHAR[260 * MAX_FILES]()); // 최대 파일 수에 맞게 힙에 버퍼를 할당합니다.

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

        // 단일 파일 선택의 경우
        if (fileInfos.empty()) {
            std::wstring fileName = directory.substr(directory.find_last_of(L"\\") + 1);
            fileInfos.push_back({ fileName, directory });
        }
    }

    return fileInfos;
}

void FileLoader::GroupAndCopyFiles(const std::vector<FileLoader::FileInfo>& fileInfos) {
    std::unordered_map<std::wstring, std::vector<FileLoader::FileInfo>> groups;

    // 파일 이름에서 그룹을 나눕니다.
    for (const auto& fileInfo : fileInfos) {
        size_t pos = fileInfo.fileName.find(L"_", fileInfo.fileName.find(L"_") + 1);
        if (pos != std::wstring::npos) {
            std::wstring groupName = fileInfo.fileName.substr(0, pos);
            groups[groupName].push_back(fileInfo);
        }
    }

    // 그룹별로 파일을 처리합니다.
    for (const auto& group : groups) {
        std::wstring combinedFilePath;       // _combined.csv 파일 경로
        std::vector<std::wstring> otherFilePaths;  // _Unity.csv 외의 다른 CSV 파일 경로

        // 그룹 내 모든 파일을 확인합니다.
        for (const auto& fileInfo : group.second) {
            if (fileInfo.fileName.find(L"_Unity.csv") != std::wstring::npos) {
                // _Unity.csv를 _combined.csv로 복사
                combinedFilePath = fileInfo.filePath.substr(0, fileInfo.filePath.find_last_of(L"\\"))
                    + L"\\" + group.first + L"_combined.csv";

                std::ifstream src(fileInfo.filePath, std::ios::binary);
                std::ofstream dst(combinedFilePath, std::ios::binary);
                dst << src.rdbuf();
            }
            else {
                // _Unity.csv가 아닌 나머지 파일 경로를 저장
                otherFilePaths.push_back(fileInfo.filePath);
            }
        }

        // 그룹에 _combined.csv와 다른 CSV 파일들이 모두 존재할 경우 병합 수행
        if (!combinedFilePath.empty() && !otherFilePaths.empty()) {
            // 기본 디렉토리는 그룹의 첫 번째 파일 경로에서 추출 (출력 파일 경로 생성을 위해)
            std::wstring baseDirectory = group.second.front().filePath.substr(0, group.second.front().filePath.find_last_of(L"\\"));
            std::wstring outputPath = baseDirectory + L"\\" + group.first + L"_merged.csv";

            // CSVController의 병합 기능 호출
            // (CSVController::mergeGroupFilesAdvanced는 combinedPath, otherPaths, outputPath를 인자로 받아 병합된 파일을 생성)
            CSVController::mergeGroupFilesAdvanced(combinedFilePath, otherFilePaths, outputPath);
        }
    }
}
