#include "Vector.h"

Vector::Vector(Direction* d, Colour* c) {
	this->d = d;
	this->c = c;
}

Direction* Vector::getDirection() {
	return this->d;
}

Colour* Vector::getColour() {
	return this->c;
}