#pragma once
#include "Item.h"

class Mirror :public Item {
public:
	Mirror(RelativePoint* p, int angle = 0);
	Mirror(const Mirror&) = default;
	string getImage()const;
	list<Vector*> getLight(Vector* from);
};