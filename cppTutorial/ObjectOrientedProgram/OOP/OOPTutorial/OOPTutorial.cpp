#include <iostream>

using namespace std;

#include "Player.h"

// ��ü ����
// ������ + ����


int main() {

	// ��ü ������ ������ ���� ������ �����Ѵ�.
	Player k1; // ���� ������ ��ü ����
	k1.m_hp = 200;
	k1.Attack();
	Player k2(100, 10, 1); // ��Ÿ ������ �̿�

	Player k3(k2); // ���� ������ �̿�
}