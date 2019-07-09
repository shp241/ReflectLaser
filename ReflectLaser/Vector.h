#pragma once
#include "Colour.h"
#include "RelativePoint.h"

class Vector {//向量类，用于标记空方块内的光线方向及颜色
private:
	Colour* c;//向量的颜色
	Direction* d;//向量的方向
	RelativePoint* p;
public:
	Vector(Direction* d, Colour* c, RelativePoint* p);
	Vector(const Vector& v, RelativePoint* p);
	Direction* getDirection()const;
	Colour* getColour()const;
	RelativePoint* getPosition()const;
	bool operator==(const Vector& v)const;
	~Vector();
};
