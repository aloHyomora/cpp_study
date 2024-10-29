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

	const char* name1 = str.c_str();
#pragma endregion

	// 1) ASCII 코드 -> 영어만 고려
	// char(1) 0~255
	char a1 = 'A';
	// 7bit (0~127)

	// 2) ANSI << 동일한 키코드 = 동일한 문자
	// ASCII + 각국 언어별로 128
	// CP949(한국어 포맷)

	// 3) 유니코드 (동일 번호 = 동일한 문자 = 동일한 유니코드)
	// - 인코딩 (utf8, utf16)
	// - utf8 : 영어(1바이트), 한국어/중국어(3바이트)
	// - utf16 : 영어(2바이트), 한국(2),중국(2)	-> 동시 서비스라면 utf16으로!

	// 문자는 무조건 1바이트다. 는 틀렸다.

	setlocale(LC_ALL, "");
	cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << endl;	// 윈도우 언어가 한글

	// ? 이걸 중국에서 보면 깨질 수 있다. 왜냐하면 중국 쪽 포맷에는 대응되지 않는 키코드가 있기 때문.
	const char* test = "aaa한국어";
	cout << test << endl;

	auto test3 = u8"aaa김효입니다.";	// utf8로 인코딩
	setlocale(LC_ALL, "en_US.UTF-8"); // utf-8로 맞춰주기
	cout << test3 << endl;

	auto test4 = u"aaa김효입니다";
}
