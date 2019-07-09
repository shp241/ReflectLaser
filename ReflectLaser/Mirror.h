#pragma once
#include "Item.h"

class Mirror :public Item {
public:
	Mirror(RelativePoint* p = new RelativePoint(), int angle = 0);
	Mirror(const Mirror& m);
	void draw()const;
	list<Vector*> getLight(Vector* from);
};