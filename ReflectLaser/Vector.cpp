#include "Vector.h"

Vector::Vector(Direction* d, Colour* c) {
	this->d = d;
	this->c = c;
}

Direction* Vector::getDirection()const {
	return this->d;
}

Colour* Vector::getColour()const {
	return this->c;
}

Vector::~Vector() {
	delete c;
	delete d;
}