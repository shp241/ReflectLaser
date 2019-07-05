#pragma once
#include "RelativePoint.h"
#include <string>
using std::string;

class Block {
private:
	RelativePoint* p;
public:
	Block(RelativePoint* p);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	virtual bool isEmpty();
	virtual bool canMove();
	virtual string getImage();
	virtual ~Block();
};
