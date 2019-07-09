#pragma once
#include "Item.h"

class HalfMirror :public Item {
public:
	HalfMirror(RelativePoint* p, int angle = 0);
	HalfMirror(const HalfMirror&) = default;
	void draw()const;
	list<Vector*> getLight(Vector* from);
};