#pragma once
#include "EmptyBlock.h"

class Map {
private:
	Block* game[15][15];
public:
	Map();
	Block* operator[](RelativePoint p);//����Blockָ��
	void change(RelativePoint* p, Block* b);
};