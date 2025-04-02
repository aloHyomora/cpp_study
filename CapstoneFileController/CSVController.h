#pragma once

#include <string>
#include <vector>

class CSVController {
public:
    // combinedPath: _combined.csv 파일 경로 (4열에 시간 데이터)
    // otherPaths: 그룹 내 다른 CSV 파일 경로들 (3열에 시간 데이터)
    // outputPath: 병합 결과로 생성할 파일 경로
    static void mergeGroupFilesAdvanced(const std::wstring& combinedPath,
        const std::vector<std::wstring>& otherPaths,
        const std::wstring& outputPath);
};
