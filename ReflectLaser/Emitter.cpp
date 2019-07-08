#include "Emitter.h"

Emitter::Emitter(RelativePoint* p, Colour* colour, int angle) :Block(p, false) {
	this->angle = angle;
	this->vector = new Vector(new Direction(angle), new Colour(*colour), p);
}

void Emitter::role() {}

int Emitter::getAngle()const {
	return angle;
}

Colour* Emitter::getColour()const {
	return vector->getColour();
}

Vector* Emitter::getVector()const {
	return vector;
}

string Emitter::getImage()const {
	return "Block\\Emitter\\Emitter_" + to_string(Colour::getColourNumber(colour)) + "_" + to_string(angle);
}

list<Vector*> Emitter::getLight(Vector* from) {
	return list<Vector*>{};
}

Emitter::~Emitter() {
	delete vector;
}