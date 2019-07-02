#pragma once
#include "Colour.h"
#include "Point.h"
class Vector {
private:
	Colour* c;
	Point* p;
public:
	Vector(Direction* p, Colour* c);
};