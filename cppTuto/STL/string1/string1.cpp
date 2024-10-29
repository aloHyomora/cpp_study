#include <iostream>

using namespace std;
#include <algorithm>

int main()
{

#pragma region C style stirng
	// C 스타일 문자열
	const char* name = "Rookiss";
	const char* name2 = "Rookiss";

	if (name == name2)
		cout << "같음" << endl;
	else
		cout << "다름" << endl;

	// 스택 영역에 값을 만들어 넣어줌.
	// 단순히 주소값을 비교하기 때문에 다르다고 함.
	char name3[] = "Rookiss";
	char name4[] = "Rookiss";

	if (name3 == name4)
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
#pragma endregion
	
#pragma region dd
	// string 클래스 이용하는 데 초점을 맞추면 된다.
	std::string str = "Tomas";
	std::string str2 = "Tomas";

	// 1) 비교 (ex. id, pw 비교)
	if (str == str2) {

	}

	// 2) 복사 (원본에 영향을 준다?>) 주지 않는다.
	string str3;
	str3 = str;
	
	// 3) 추가()
	str.append("1234");
	str += "5678";	// 오버로딩 되어 있음.

	// 4) 찾기
	auto c = str.find("To"); // 인덱스 반환
	if (c == std::string::npos) {
		cout << "not found";
	}

	// 5) 교체
	string chatStr = "Shit!!";
	string findStr = "Shit";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	string str4 = str.substr(0, 3);

	const char* name = str.c_str();
#pragma endregion


}
