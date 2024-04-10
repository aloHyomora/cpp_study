#include <iostream>
#include <cstring> // to use strlen()

using namespace std;

int main(int argc, char* argv[]) // 공백 white space
{
    const int size = 15;
    char name1[size];                   // empty array
    char name2[size] = "C++programing"; // initialized array with string

    cout << "Hello! My Name? " << name2;
    cout << ".. ! What's yours? \n";
    // cin >> name1;
    cin.getline(name1, size);
    cout << "Mr." << name1 << "'s Length is ";
    cout << strlen(name1) << "\n";
    cout << "It is stored in an array with a size of "<< sizeof(name1) << "bytes.\n";
    cout << "First Name is " << name1[0] << "\n";
    cout << "My first three word on my Name is ";
    name2[3] = '\0';
    cout << name2 << endl;

    // cin can't detect white spcae ex) Kim Jeong Hyo -> Length : 3


    /*
     * can Initialize string object with C Style
     */

	// string 타입은 array(배열) 타입과 다르게 변수에서 변수로 할당이 가능하다.
    return 0;
}
