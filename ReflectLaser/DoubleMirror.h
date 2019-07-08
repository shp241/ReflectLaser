#pragma once
#include "Item.h"

class DoubleMirror :public Item {
public:
	DoubleMirror(RelativePoint* p, int angle = 0);
	string getImage()const;
};