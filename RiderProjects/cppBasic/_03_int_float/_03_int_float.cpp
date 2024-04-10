#include <iostream>
// #include <climits>
using namespace std;

int main(int argc, char* argv[])
{
    // integer type
    // short, int, long, long long

    // Important to declare data types considering memory performance
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int는 " << sizeof n_int << "바이트이다." << endl;
    cout << "이 바이트의 최대값은 " << n_int << " 이다." << endl;
    
    cout << "short은 " << sizeof n_short << "바이트이다." << endl;
    cout << "이 바이트의 최대값은 " << n_short << " 이다." << endl;
    
    cout << "long은 " << sizeof n_long << "바이트이다." << endl;
    cout << "이 바이트의 최대값은 " << n_long << " 이다." << endl;
    
    cout << "long long은 " << sizeof n_llong << "바이트이다." << endl;
    cout << "이 바이트의 최대값은 " << n_llong << " 이다." << endl;

    unsigned short a = -1;
    cout << "unsigned short a[-1] : " << a << endl;

    // float
    float f = 3.14;
    int b = 3.14;

    cout << f << " " << b << endl;
    

    
    return 0;
}
