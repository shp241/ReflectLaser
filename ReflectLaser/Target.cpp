#include "Target.h"

Target::Target(Colour* colour, RelativePoint* p) :EmptyBlock(p) {
	this->colour = colour;
}

bool Target::isSucceeded()const {
	Colour c = Colour::COLOUR_BLACK;
	for (int i = 0; i < 8; i++) {
		c += this->getVectorColour(i);
	}
	return c == colour;
}

string Target::getImage()const {
	return "Block\\Target\\" + isSucceeded() ? "Succeeded_" : "Target_" + to_string(Colour::getColourNumber(colour));
}

Colour* Target::getColour()const {
	return colour;
}

void Target::role() {}

Target::~Target() {
	delete colour;
}