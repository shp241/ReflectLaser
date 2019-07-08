<<<<<<< HEAD
#pragma once
#include "Block.h"

class Emitter :public Block {
private:
	int angle;
	Colour* colour;
public:
	Emitter(RelativePoint* p, Colour* colour, int angle = 0);
	void role();
	int getAngle()const;
	Colour* getColour()const;
	string getImage()const;
=======
#pragma once
#include "Block.h"

class Emitter :public Block {
private:
	int angle;
	Colour* colour;
public:
	Emitter(RelativePoint* p, Colour* colour, int angle = 0);
	void role();
	int getAngle()const;
	Colour* getColour()const;
	string getImage()const;
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
};