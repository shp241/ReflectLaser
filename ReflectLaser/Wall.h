#pragma once
#include "Block.h"

class Wall :public Block {
public:
	Wall(RelativePoint* p);
	Wall(const Wall&) = default;
	string getImage()const;
	list<Vector*> getLight(Vector* from);
	~Wall() = default;
};