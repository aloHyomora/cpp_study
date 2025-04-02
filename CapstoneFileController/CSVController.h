#pragma once

#include <string>
#include <vector>

class CSVController {
public:
    // combinedPath: _combined.csv ���� ��� (4���� �ð� ������)
    // otherPaths: �׷� �� �ٸ� CSV ���� ��ε� (3���� �ð� ������)
    // outputPath: ���� ����� ������ ���� ���
    static void mergeGroupFilesAdvanced(const std::wstring& combinedPath,
        const std::vector<std::wstring>& otherPaths,
        const std::wstring& outputPath);
};
