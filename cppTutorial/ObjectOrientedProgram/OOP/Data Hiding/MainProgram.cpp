#include <iostream>
using namespace std;

// OOP 3�� ���
// - ��Ӽ� << inheritance (�����޴´�..)
// - ���м� << data hiding (Encapsulization)
// - ������

// �ڵ���
// �ڵ�, ���, ����, ���⼱, �ֹ���
// ������ ���忡�� ��� : �ڵ�, ���, ��
// ���� �� : ����, ���⼱

// ====== ���� ������ =======
// public, 
// protected(��ȣ�޴�, �� �ڼո� ��� ����), 
// private

// ====== ��� ���� ������ ======
// ������������ �θ���� ������ ��� ��������?
// public
// protected �� �ڽĵ������ �����ٰž�
// private
class Car {
public:
	void MoveHandle(){}
	void PushPedal(){}
	void OpenDoor(){}	
	void SetHorsePower(int power) {
		m_horsePower = power;
	}
	int GetHorsePower() {
		return m_horsePower;
	}

private:
	// �Ʒ� ����� ����ڰ� �˾Ƽ� �ȵȴ�. (������ �� �����ϴ� �� ������ �ȴ�.)
	void Disassemble(){}
	void PutFuelInEngine(){}

private: // ��� ������ ���� �����ؼ� �����ϴ� �� ���� ���δ�. SetHp, GetHp ����� ����ϴ� �� ����.
	int m_horsePower = 500;
	// �ڵ� 
	// ��� 
	// ���� 
	// �� 
	// ���⼱
};

int main() {
	Car c;
	
}