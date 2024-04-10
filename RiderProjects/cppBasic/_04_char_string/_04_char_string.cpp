#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // char : small character type. one Word from ASCII code
    int a = 77;
    char b = a;
    cout << b << endl;

    // to set Value in char variable, You must use single quotes => ''
    // in c++, null word '\0' means the end of word, string
    // c++ detect end of word, string. developer need to set null 
    char c = 'c'; 
    cout << c << endl;

    char arrangeChar[] = {'a','b','c'}; 
    cout << arrangeChar << endl;

    char arrangeChar_null[] = {'a','b','c','\0'}; 
    cout << arrangeChar_null << endl;
    
    // "" >> null word is explicitly included in double quotes. => string 
    // char d = "a"; => "a" has word 'a', '\0'

    // bool : 0 or 1 (0 is false, 1 is true)
    bool g = 0;
    bool g1 = 1;
    bool g2 = 2;

    cout << g << " " << g1 << " " << g2 << endl;
    return 0;
}
