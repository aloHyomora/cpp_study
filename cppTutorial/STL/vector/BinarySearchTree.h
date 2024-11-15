#pragma once

struct  Node {
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = 0;
};
class BinarySearchTree
{
public:
	void Print() { Print(m_root, 10, 0); }
	void Print(Node* node, int x, int y);
	void Insert(int key);
	Node* Search(Node* node, int key);

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);
	void Replace(Node* u, Node* v);
	void Delete(Node* node);
	void Delete(int key);
public:
	Node* m_root = nullptr;
};

