<<<<<<< HEAD
#include "Emitter.h"

Emitter::Emitter(RelativePoint* p, Colour* colour, int angle = 0) :Block(p) {
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
=======
#include "Emitter.h"

Emitter::Emitter(RelativePoint* p, Colour* colour, int angle = 0) :Block(p) {
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
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
}