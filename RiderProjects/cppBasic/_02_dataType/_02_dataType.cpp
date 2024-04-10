#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // 1. variable : changeable data
    // cf) const : non-changeable data

    /*
     * 1. variable Data Type
     * 2. variable naming
     * 3. Where are variables stored?     
     */

    // Naming Convention
    /*
     * 1. can't start with number                 
     * 2. can't use keyword that c++ using, the same naming    
     * 3. can't use white space
     */

    // naming error example
    /*
     * int 123abc;
     * int return;
     * int ab cd;
     */


	int a;
	a = 1;
	
	int b = 3;

	cout << "a = " << a << ", b = " << b << endl;
		
	// if you want to know data's Adress
	cout << "a = " << &a << ", b = " << &b << endl;
	
    return 0;

}
