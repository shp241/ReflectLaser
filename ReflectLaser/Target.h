#pragma once
#include "Block.h"

class Target :public Block {
private:
	Colour* colour;
public:
	Target(Colour* colour, RelativePoint* p = new RelativePoint());
	bool isSucceeded()const;
	virtual string getImage()const;
	Colour* getColour()const;
	void role();
	~Target();
};