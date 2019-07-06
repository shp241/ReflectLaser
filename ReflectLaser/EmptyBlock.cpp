#include "EmptyBlock.h"

EmptyBlock::EmptyBlock(RelativePoint* p) :Block(p) {
	clear();
}

string EmptyBlock::getImage() {
	return "Block\\EmptyBlock";
}

Colour& EmptyBlock::operator[](int n) {
	return vectors[n];
}

void EmptyBlock::addVector(Vector* v) {
	vectors[Direction::getDirectionNumber(*v->getDirection())] += *v->getColour();
}

void EmptyBlock::clear() {
	for (int i = 0; i < 4; i++) {
		vectors[i] = Colour::BLACK;
		vectors[i + 4] = Colour::BLACK;
	}
}

EmptyBlock::~EmptyBlock() {
	delete vectors;
}