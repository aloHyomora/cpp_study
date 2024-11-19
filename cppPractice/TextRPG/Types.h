#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Stat {
	int32 hp = 0;
	int32 maxHp = 0;
	int32 attack = 0;
	int32 defence = 0;

	Stat(int _hp = 0, int _maxHp = 0, int _attack = 0, int _defence = 0)
		: hp(_hp), maxHp(_maxHp), attack(_attack), defence(_defence) { }
};