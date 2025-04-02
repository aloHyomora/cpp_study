#pragma once

#include <string>
#include <vector>
#define MAX_FILES 200
class FileLoader {
public:
    struct FileInfo {
        std::wstring fileName;
        std::wstring filePath;
    };

    static std::vector<FileInfo> OpenFileDialog();
    static void GroupAndCopyFiles(const std::vector<FileInfo>& fileInfos);
};

