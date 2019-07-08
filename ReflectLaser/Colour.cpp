#include "Colour.h"

Colour Colour::COLOUR_RED = Colour(true, false, false);
Colour Colour::COLOUR_GREEN = Colour(false, true, false);
Colour Colour::COLOUR_BLUE = Colour(false, false, true);
Colour Colour::COLOUR_CYAN = Colour(false, true, true);
Colour Colour::COLOUR_YELLOW = Colour(true, true, false);
Colour Colour::COLOUR_MAGENTA = Colour(true, false, true);
Colour Colour::COLOUR_BLACK = Colour(false, false, false);
Colour Colour::COLOUR_WHITE = Colour(true, true, true);
Colour Colour::colours[] = { COLOUR_BLACK, COLOUR_RED, COLOUR_GREEN, COLOUR_BLUE, COLOUR_CYAN, COLOUR_MAGENTA, COLOUR_YELLOW, COLOUR_WHITE };

Colour::Colour(bool r, bool g, bool b) {
	this->R = r;
	this->G = g;
	this->B = b;
}

int Colour::getColourNumber(Colour d) {
	for (int i = 0; i < 8; i++) {
		if (colours[i] == d) {
			return i;
		}
	}
	return 0;
}

Colour Colour::getNumberColour(int i) {
	return colours[i % 8];
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