#include "Colour.h"

const Colour Colour::RED = Colour(true, false, false);
const Colour Colour::GREEN = Colour(false, true, false);
const Colour Colour::BLUE = Colour(false, false, true);
const Colour Colour::CYAN = Colour(false, true, true);
const Colour Colour::YELLOW = Colour(true, true, false);
const Colour Colour::MAGENTA = Colour(true, false, true);
const Colour Colour::BLACK = Colour(false, false, false);
const Colour Colour::WHITE = Colour(true, true, true);

Colour::Colour(bool r, bool g, bool b) {
	this->R = r;
	this->G = g;
	this->B = b;
}

bool Colour::operator==(Colour c) {
	return c.R == this->R && c.G == this->G && c.B == this->B;
}

Colour Colour::operator+(Colour c) {
	return Colour(c.R || this->R, c.G || this->G, c.B || this->B);
}

void Colour::operator+=(Colour c) {
	this->R = c.R || this->R;
	this->G = c.G || this->G;
	this->B = c.B || this->B;
}

int Colour::getComplexity()const {
	return R + G + B;
}