#pragma once
#include "EmptyBlock.h"

class Target:public EmptyBlock {
private:
	Colour* colour;
public:
	Target(Colour* colour,RelativePoint* p=new RelativePoint());
	bool isSucceeded()const;
	virtual string getImage()const;
	Colour* getColour()const;
	~Target();
};