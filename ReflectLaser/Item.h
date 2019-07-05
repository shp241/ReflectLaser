#pragma once
#include "Block.h"
class Item :public Block {
private:
	bool isUsed;
public:
	Item(bool used);
	Item(const Item& it);
};