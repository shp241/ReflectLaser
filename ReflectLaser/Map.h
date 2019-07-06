#pragma once
#include "EmptyBlock.h"

class Map {
private:
	Block* game[15][15];
public:
	Map();
	Map(const Map& m);
	Block* operator[](RelativePoint p)const;//∑µªÿBlock÷∏’Î
	void change(RelativePoint* p, Block* b);
	~Map();
};