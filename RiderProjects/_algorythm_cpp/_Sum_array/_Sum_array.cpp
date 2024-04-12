// _Sum_array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
// #include <alogorithm>
using namespace std;
int main()
{
    // 1. 시간 복잡도 잘 따지는지
    // 2. 두 수로 조합을 해서 좋은 수를 많든다는 것을 가지고 투 포인트를 떠올릴 수 있는지
    // 3. 조건이 정수이기 때문에 조합 계산에 자기 자신이 들어갈 수 있어. 예외처리 해줄 수 있는지
    std::cout << "Hello World!\n";

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n, 0);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int Result = 0;

    // 알고리즘 만들기

    for (int k = 0; k < n; k++)
    {
        long find = A[k]; // A[k] 값이 우리가 검사하려는 수. (두 수의 합으로 표현가능한지)
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (A[i] + A[j] == find) {
                if (i != k && j != k) {
                    Result++;
                    break;
                }
                else if (i == k) {
                    i++;
                }
                else if (j == k)
                {
                    j--;
                }
            }
            else if (A[i] + A[j] < find)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    cout << Result << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
