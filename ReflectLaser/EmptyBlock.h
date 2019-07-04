#pragma once
#include "Colour.h"
#include "Block.h"
#include "Vector.h"

class EmptyBlock :public Block {
private:
	Colour lines[4] = { Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK };
public:
	Colour vectors[8] = { Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK };
	EmptyBlock(RelativePoint* p) :Block(p);
	void draw();
	Colour& operator[](int n);
	void addVector(Vector* v);
	void clear();
};
