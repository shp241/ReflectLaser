#include "Target.h"

Target::Target(Colour* colour, RelativePoint* p) :Block(p) {
	this->colour = colour;
}

bool Target::isSucceeded()const {
	Colour c = Colour::COLOUR_BLACK;
	for (int i = 0; i < 8; i++) {
		c += this->getVectorColour(i);
	}
	return c == colour;
}

void Target::draw()const {
	Picture::putPicture("Block\\Target\\" + isSucceeded() ? "Succeeded_" : "Target_" + to_string(Colour::getColourNumber(colour)),
		*getPosition()->getActualPoint());
	for (int i = 0; i < 8; i++) {
		Vector* v0 = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(getVectorColour(i) + getVectorColour(i + 4)), new RelativePoint(*getPosition()));
		Vector* v1 = new Vector(new Direction(Direction::getNumberDirection(i).rotate(180)), new Colour(getVectorColour(i) + getVectorColour(i + 4)), new RelativePoint(*getPosition()));
		Picture::drawVector(v0);
		Picture::drawVector(v1);
		delete v0;
		delete v1;
	}
}

Colour* Target::getColour()const {
	return colour;
}

list<Vector*> Target::getLight(Vector* from) {
	return Block::getLight(from);
}

Target::~Target() {
	delete colour;
}