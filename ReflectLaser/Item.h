#pragma once
#include "Block.h"

class Item :public Block {//所有道具的基类
private:
	int angle;
public:
	Item(RelativePoint* p, bool empty = true, int angle = 0);
	Item(const Item& it);
	void rotate(bool isClock);//true则为顺时针旋转，false则为逆时针
	int getAngle()const;
	void setAngle(int angle);
	virtual void draw()const;
	virtual list<Vector*> getLight(Vector* from);
	~Item();
};