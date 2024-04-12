#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    vector<int> A;

    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);
    A.insert(A.begin(),0);
    A.insert(A.begin() + 2,4);

    A[4] = -5;

    A.pop_back();

    A.erase(A.begin() + 3);

    cout << A.size() << endl;
    cout << A.front() << endl;
    cout << A.back() << endl;
    cout << A[3] << endl;
    cout << A.at(5) << endl;
    
    A.clear();
    return 0;
}
