#include <iostream>

using namespace std;

class Node {
public:
    Node(int data) :m_data(data){}
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    
    int m_data;
};

int main()
{

    // 단방향 리스트
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // 양방향 리스트, [1] <-> [2] <-> [3] <-> [4] 
    // [head] <->                        <-> [tail]
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n6->next = n7;

    n7->prev = n6;
    n7->next = n8;

    n8->prev = n7;
    n8->next = n9;

    n9->prev = n8;
    n9->next = n10;

    n10->prev = n9;
}
