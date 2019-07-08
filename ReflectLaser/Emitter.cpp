#include "Emitter.h"

Emitter::Emitter(RelativePoint* p, Colour* colour, int angle) :Block(p, false) {
	this->angle = angle;
	this->colour = new Colour(*colour);
}

void Emitter::role() {}

int Emitter::getAngle()const {
	return angle;
}

Colour* Emitter::getColour()const {
	return colour;
}

string Emitter::getImage()const {
	return "Block\\Emitter\\Emitter_" + to_string(Colour::getColourNumber(colour)) + "_" + to_string(angle);
}

Emitter::~Emitter() {
	delete colour;
}