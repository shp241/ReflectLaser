#pragma once
#include "EmptyBlock.h"

class Map {
private:
	Block* game[15][15];
public:
	Map();
	Block* operator[](RelativePoint p);//∑µªÿBlock÷∏’Î
	void change(RelativePoint* p, Block* b);
};