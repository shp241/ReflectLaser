#include "Vector.h"

Vector::Vector(Direction* d, Colour* c, RelativePoint* p) {
	this->d = d;
	this->c = c;
	this->p = p;
}

Vector::Vector(const Vector& v, RelativePoint* p) {
	this->d = v.d;
	this->c = v.c;
	this->p = p;
}

Direction* Vector::getDirection()const {
	return this->d;
}

Colour* Vector::getColour()const {
	return this->c;
}

RelativePoint* Vector::getPosition()const {
	return this->p;
}

Vector::~Vector() {
	delete c;
	delete d;
	delete p;
}