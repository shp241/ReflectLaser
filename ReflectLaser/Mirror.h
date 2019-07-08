<<<<<<< HEAD
#pragma once
#include "Item.h"

class Mirror :public Item {
public:
	Mirror(RelativePoint* p, int angle = 0);
	Mirror(const Mirror&) = default;
	string getImage()const;
=======
#pragma once
#include "Item.h"

class Mirror :public Item {
public:
	Mirror(RelativePoint* p, int angle = 0);
	Mirror(const Mirror&) = default;
	string getImage()const;
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
};