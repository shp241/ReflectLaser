#pragma once
#include "RelativePoint.h"
class Block {
private:
	RelativePoint* p;
public:
	Block(RelativePoint* p);
    RelativePoint* getPosition();
    Virtual bool isEmpty();
    Vittual bool canMove();
    Virtual void draw();
};
