#include <iostream>
#include "DataStructure/List.h"
int main(int argc, char* argv[])
{
    List list;

    list.AddAtTail(1);
    Node* node = list.AddAtTail(2);
    list.AddAtTail(3);

    list.Print();

    list.Remove(node);
    list.Print();
    
    return 0;
}
