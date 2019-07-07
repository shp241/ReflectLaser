#include "Target.h"

Target::Target(Colour* colour, RelativePoint* p = new RelativePoint()) :EmptyBlock(p){
	this->colour = colour;
}

bool Target::isSucceeded()const {
	Colour c = Colour::BLACK;
	for (int i = 0; i < 8; i++) {
		c += this->getVectorColour(i);
	}
	return c == colour;
}

string Target::getImage()const {
	return "Block\\Target\\" + isSucceeded() ? "Succeeded_" : "Target_" + Colour::getColourNumber(colour);
}

Colour* Target::getColour()const {
	return colour;
}

Target::~Target() {
	delete colour;
}
