#pragma once
#include "Colour.h"
#include "Point.h"
class Vector {
private:
	Colour* c;
	Direction* d;
public:
	Vector(Direction* d, Colour* c);
	Direction* getDirection();
	Colour* getColour();
};
