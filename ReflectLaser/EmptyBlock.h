#pragma once
#include "Colour.h"
#include "Block.h"
#include "Vector.h"

class EmptyBlock :public Block {
private:
	Colour lines[4];
public:
	Colour vectors[8];
	EmptyBlock(RelativePoint* p);
	string getImage();
	void addVector(Vector* v);
	void clear();
	Colour& operator[](int n);
	~EmptyBlock();
};
