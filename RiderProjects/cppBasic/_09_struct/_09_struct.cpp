#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // struct(구조체) : A set of data that allows different data formats
    // cf) array(배열) : A set of same data formats

    // football player info
    string name;
    string position;
    float height;
    float weight;

    // football player info : struct
    // declare struct 
    struct footballPlayerStat
    {
        // it called member 
        string name;
        string position;
        float height;
        float weight;
    }mem;

    // Initialize struct variable 1
    footballPlayerStat A;
    A.name = "Son";
    A.position = "RW";
    A.height = 183.0;
    A.weight = 77;

    // Initialize struct variable 2
    footballPlayerStat B ={
        "Kane",
        "ST",
        187.5,
        80
    };

    cout << A.name << endl;
    cout << B.name << endl;


    // 구조체 생성 시 만든 변수 mem
    mem ={
    };
    cout << mem.height << endl;

    footballPlayerStat players[2] = {
        {"A", "A", 1, 1},
        {"B", "B", 2, 2}
    };

    cout << players[0].name << endl;
    cout << players[1].height << endl;
    
    return 0;
}
