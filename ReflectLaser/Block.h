#pragma once
#include "RelativePoint.h"
class Block {
private:
	RelativePoint* p;
public:
	Block(RelativePoint* p);
	RelativePoint* getPosition();
	virtual bool isEmpty();
	virtual bool canMove();
	virtual void draw();
};
