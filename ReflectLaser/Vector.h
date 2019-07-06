#pragma once
#include "Colour.h"
#include "Point.h"

class Vector {//向量类，用于标记空方块内的光线方向及颜色
private:
	Colour* c;//向量的颜色
	Direction* d;//向量的方向
public:
	Vector(Direction* d, Colour* c);
	Direction* getDirection()const;
	Colour* getColour()const;
	~Vector();
};
