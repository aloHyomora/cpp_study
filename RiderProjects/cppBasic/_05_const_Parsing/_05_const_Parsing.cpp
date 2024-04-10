#include <iostream>
// #define PI 3.141592 : const c style

using namespace std;

int main(int argc, char* argv[])
{
    
    // get area of a circle
    int r = 3;
    float area = r * r * 3.141592;

    cout << area << endl;

    // 1. doesn't need to change
    // 2. shouldn't change
    // const (상수)

    const float pi = 3.141592;
    float areaC = r * r * pi;
    cout << areaC << endl;
    
    // Parsing Daya Type
    /*
     * 1. When assigning a value of another data type to a variable of a specific data type
     * 2. When using mixed data types in formulas
     * 3. When passing parameters to a function
     */

	// 1. typeName(a), (typeName) a 
	// 2. static_cast<typeName> c++
	char ch = 'M';
	cout << int(ch) << " " << (int)ch << " " <<static_cast<int>(ch) << endl;

	// result : 77 77 77
	
    return 0;
}
