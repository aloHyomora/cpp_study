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




int main()
{
#pragma region lambda
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
}

