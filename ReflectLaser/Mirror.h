#pragma once
#include "Item.h"

class Mirror :public Item {
public:
	Mirror(RelativePoint* p = new RelativePoint(), int angle = 0);
	Mirror(const Mirror&) = default;
	void draw()const;
	list<Vector*> getLight(Vector* from);
};