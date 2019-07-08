#pragma once
#include "Block.h"

class Item :public Block {//所有道具的基类
private:
	int angle;
public:
	Item(RelativePoint* p, bool empty = true);
	Item(const Item& it);
	Item(const Item& it, RelativePoint* p);
	void rotate(bool isClock);//true则为顺时针旋转，false则为逆时针
	virtual string getImage()const;
};