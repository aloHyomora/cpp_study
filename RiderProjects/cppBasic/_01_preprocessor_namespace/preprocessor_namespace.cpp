#include <iostream>
/* c++ 에서 함수를 사용하려면 그 함수의 원형을 미리 정의해야 한다.*/

using namespace std;

int main()
{
    // c++ code needs Method that called "main"
    
    cout << "Hello, World!" << endl;
    // endl means line break
    // << flow of data
    // In a nutshell, cout! Print string type ("Hello, World!")

    std::cout << "Hello, World!" << std::endl;
    // cout method is included in std Namespace.
    // 'using namespace std' makes enable to use cout method

    return 0;
}
