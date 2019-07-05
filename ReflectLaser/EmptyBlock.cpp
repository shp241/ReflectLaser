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

int getDirectionNumber(Direction d) {
	if (d == Direction::UP) {
		return 0;
	}
	if (d == Direction::UP_RIGHT) {
		return 1;
	}
	if (d == Direction::RIGHT) {
		return 2;
	}
	if (d == Direction::DOWN_RIGHT) {
		return 3;
	}
	if (d == Direction::DOWN) {
		return 4;
	}
	if (d == Direction::DOWN_LEFT) {
		return 5;
	}
	if (d == Direction::LEFT) {
		return 6;
	}
	if (d == Direction::UP_LEFT) {
		return 7;
	}
}

void EmptyBlock::addVector(Vector* v) {
	vectors[getDirectionNumber(*v->getDirection())] += *v->getColour();
	lines[getDirectionNumber(*v->getDirection()) % 4] += *v->getColour();
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