#pragma once
#include "Item.h"

class DoubleMirror :public Item {
public:
	DoubleMirror(RelativePoint* p = new RelativePoint(), int angle = 0);
	DoubleMirror(const DoubleMirror&) = default;
	void draw()const;
	list<Vector*> getLight(Vector* from);
};