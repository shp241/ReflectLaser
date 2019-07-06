#include "EmptyBlock.h"

EmptyBlock::EmptyBlock(RelativePoint* p) :Block(p) {
	clear();
}

string EmptyBlock::getImage() {
	return "emptyBlock";
}

Colour& EmptyBlock::operator[](int n) {
	return vectors[n];
}

void EmptyBlock::addVector(Vector* v) {
	vectors[Direction::getDirectionNumber(*v->getDirection())] += *v->getColour();
	lines[Direction::getDirectionNumber(*v->getDirection()) % 4] += *v->getColour();
}

void EmptyBlock::clear() {
	for (int i = 0; i < 4; i++) {
		vectors[i] = Colour::BLACK;
		vectors[i + 4] = Colour::BLACK;
		lines[i] = Colour::BLACK;
	}
}

EmptyBlock::~EmptyBlock() {
	delete lines;
	delete vectors;
}