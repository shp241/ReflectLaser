#pragma once
#include "Block.h"
#include "Colour.h"
#include "Vector.h"

class Emitter :public Block {
private:
	int angle;
	Vector* vector;
public:
	Emitter(RelativePoint* p, Colour* colour, int angle = 0);
	void role();
	int getAngle()const;
	Colour* getColour()const;
	Vector* getVector()const;
	string getImage()const;
	list<Vector*> getLight(Vector* from);
	~Emitter();
};