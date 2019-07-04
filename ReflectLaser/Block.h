#pragma once
#include "RelativePoint.h"
class Block {
private:
	RelativePoint* p;
public:
	Block(RelativePoint* p);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	virtual bool isEmpty();
	virtual bool canMove();
	virtual void draw();
	virtual ~Block();
};
