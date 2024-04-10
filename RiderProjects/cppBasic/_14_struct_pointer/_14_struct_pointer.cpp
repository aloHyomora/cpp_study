#include <iostream>
using namespace std;
struct my_struct
{
    char name[20];
    int age;
};
int main(int argc, char* argv[])
{
    my_struct* temp = new my_struct;

    cout << "Write your name\n";
    cin.getline(temp->name, 20);

    cout << "Write your age\n";
    cin >> (*temp).age;

    cout << "Hello Mr." << temp->name << " :)\n" ;
    cout << "You are " << temp->age << " years old!" << endl;
    
    return 0;
}
