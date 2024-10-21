// Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#include <vector>

class Node {
public:
    Node(const char* data) : m_data(data) {}
public:
    const char* m_data;
    vector<Node*> children;
};

Node* CreateTree() {
    Node* root = new Node("R1 개발실");
    {
        Node* node = new Node("디자인팀");
        root->children.push_back(node);
        {
            Node* leaf = new Node("전투");
            node->children.push_back(leaf);
        }

        Node* node2 = new Node("프로그래밍");
        root->children.push_back(node2);
        {
            Node* leaf = new Node("시스템");
            node2->children.push_back(leaf);
        }        
        {
            Node* leaf = new Node("백엔드");
            node2->children.push_back(leaf);
        }        
        {
            Node* leaf = new Node("프론트엔드");
            node2->children.push_back(leaf);
        }

        Node* node3 = new Node("아트");
        root->children.push_back(node3);
        {
            Node* leaf = new Node("배경");
            node3->children.push_back(leaf);
        }
        {
            Node* leaf = new Node("캐릭터");
            node3->children.push_back(leaf);
        }
        {
            Node* leaf = new Node("스토리");
            node3->children.push_back(leaf);
        }
    }

    return root;
}

// 깊이(depth): 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 개수
void PrintTree(Node* root, int depth = 0) {
    for (int i = 0; i < depth; i++)
    {
        cout << "-";
    }

    cout << root->m_data << endl;

    int size = root->children.size();
    if(size==0) return;

    for (int i = 0; i < size; i++)
    {
        Node* node = root->children[i];
        PrintTree(node, depth + 1);
    }
}

// 높이 구하기 (트리 각각의 깊이를 구하고 그 중에서 가장 큰 값을 결정함.
int GetHeight(Node* root) {
    int ret = 1;

    int size = root->children.size();
    for (int i = 0; i < size; i++)
    {
        Node* node = root->children[i];
        int h = GetHeight(node) + 1;

        if (ret < h)
            ret = h;
    }

    return ret;
}

int main()
{
    Node* root = CreateTree();

    PrintTree(root);

    int h = GetHeight(root);
}