#pragma once
#include "Block.h"

class Item :public Block {
private:
	bool isUsed;
	int angle;
public:
	Item(bool used);
	Item(const Item& it);
	void rotate(bool isClock);//true则为顺时针旋转，false则为逆时针
	virtual string getImage();
};