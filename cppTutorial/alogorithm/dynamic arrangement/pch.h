#pragma once

// pre compiled -> 맨날 사용할 것 추가하면 됨.
#include "Types.h"
#include <Windows.h>
#include <iostream>

using namespace std;

struct Pos {
	// 생성자
	Pos() {}
	Pos(int32 y, int32 x) : y(y), x(x) {}

	// 다른 값이랑 비교하기 위함
	bool operator==(const Pos& other) {
		return y == other.y && x == other.x;
	}
	bool operator!=(const Pos& other) {
		return !(*this == other); // 내자신의 주소로 타고 가서 other와 비교(특이함)
	}

	Pos operator+(const Pos& other) {
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}
	Pos operator+=(const Pos& other) {
		y += other.y;
		x += other.x;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

enum Dir {
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4
};