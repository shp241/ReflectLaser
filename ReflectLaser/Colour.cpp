#include "Colour.h"
Colour::Colour(bool r = false, bool g = false, bool b = false) {
	this->R = r;
	this->G = g;
	this->B = b;
}

bool Colour::operator==(Colour c){
	return c.R == this->R && c.G == this->G && c.B == this->B;
}

Colour Colour::operator+(Colour c) {
	return Colour(c.R || this->R, c.G || this->G, c.B || this->B);
}

int Colour::getComplexity() {
	return R + G + B;
}