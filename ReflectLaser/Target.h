#pragma once
#include "Block.h"

class Target :public Block {
private:
	Colour* colour;
public:
	Target(Colour* colour, RelativePoint* p = new RelativePoint());
	bool isSucceeded()const;
	virtual void draw()const;
	Colour* getColour()const;
	list<Vector*> getLight(Vector* from);
	~Target();
};