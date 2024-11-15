#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
enum class ItemType {
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};
enum class Rarity {
	Common,
	Rare,
	Unique
};
class Item {
public:
	Item() {}
	Item(int id, Rarity rarity, ItemType type) : m_itemId(id), m_rarity(rarity), m_type(type) {}
public:
	int m_itemId = 0;
	Rarity m_rarity = Rarity::Common;
	ItemType m_type = ItemType::None;
};


class Knight {
public:
	auto MakeResetHPJob() {
		auto job = [=]() {
			_hp = 200;
		};

		return job;
	}
public:
	int _hp = 0;

};

int main()
{
#pragma region lambda
	// 함수 객체를 편하게 만드는 것이 람다

	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(3, Rarity::Common, ItemType::Armor));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	{

		struct IsWantedItem {
			bool operator()(Item& item) {
				return item.m_itemId == wantedId;
			}
			int wantedId = 0;
		};
		IsWantedItem iswantedItem;
		iswantedItem.wantedId = 2;
		
		int wantedId = 2;	
		// = 복사
		// & 참조
		
		struct IsUniqueItem
		{
			bool operator()(Item& item) {
				return item.m_rarity == Rarity::Unique;
			}
		};

		// 알고리즘의 find_if 활용
		std::find_if(v.begin(), v.end(), IsUniqueItem());

		// 람다
		// [](){} 3종 세트를 그리고 시작, struct와 유사
		// [캡처](입력 타입){return에서 반환 타입을 판단한다.} 
		// - 명시적으로 반환 타입을 지정하려는 경우 []()int{}와 같이 한다.		
		auto isUniqueLamda = [](Item& item) { return item.m_rarity == Rarity::Unique; };

		std::find_if(v.begin(), v.end(), isUniqueLamda);

		// 캡처가 복사 타입이냐 참조 타입이냐.
		// - 참조 타입 : 주소값을 기준으로 추출
		// - [=]-> 모든 애들이 복사된다.
		// - 단일 변수마다 캡처 모드 [wantedId](Item& item){} 
		[=](Item& item) {
			return item.m_itemId == wantedId;
		};
		[&](Item& item) {
			return item.m_itemId == wantedId;
		};



	}

#pragma endregion

#pragma region lambda2
	// 람다 사용에서 위험한 경우
	// - 사실 람다의 문제는 아님. 
	// - 주소값으로 캡처할 때 이런 저런 이유에 의해서 주소가 날아갔다면 문제가 된다.

	
#pragma endregion
	Knight* k1 = new Knight();
	k1->_hp = 100;

	// 일감 예약, 근데 일감이 실행하기 전 Knigt가 죽었다면??
	auto job = k1->MakeResetHPJob();

	delete k1;

	job(); // 이미 날아간 메모리를 건드리는 작업
	// 람다가 [=] 복사 모드로 캡쳐했따면 문제가 안되지 않나?
	// - 실질적으로 [=]은 [this]와 동일. _hp와 this->_hp 동일

	[/*캡처모드*/](/*인자*/) {
		// 내용물
	};

	std::find_if(v.begin(), v.end(), [](Item& item) {return item.m_itemId == 2; });

}

