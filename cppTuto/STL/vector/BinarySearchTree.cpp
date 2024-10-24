#include "BinarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;

	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}
void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (m_root == nullptr) {
		m_root = newNode;
		return;
	}

	// 추가할 위치를 찾기
	Node* node = m_root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < parent->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;	

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);	
}

Node* BinarySearchTree::Min(Node* node)
{
	if (node == nullptr) return nullptr;
	while (node->left) // left가 있을 때까지
	{
		node = node->left;
	}
	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (node == nullptr) return nullptr;
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->left)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		m_root = v; // 원래 u가 root 노드였다.
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr) return;

	if (node->left == nullptr) {
		Replace(node, node->right);
	}
	else if (node->right == nullptr) {
		Replace(node, node->left);
	}
	else {
		// 양쪽 0
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(m_root, key);
	Delete(deleteNode);
}
