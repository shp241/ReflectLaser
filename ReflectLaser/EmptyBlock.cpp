#include "EmptyBlock.h"

EmptyBlock::EmptyBlock(RelativePoint* p) :Block(p) {
	clear();
}

string EmptyBlock::getImage()const {
	return "Block\\EmptyBlock";
}

Colour& EmptyBlock::operator[](int n) {
	return vectors[n];
}

Colour EmptyBlock::getVectorColour(int n)const {
	return vectors[n];
}

void EmptyBlock::addVector(Vector* v) {
	vectors[Direction::getDirectionNumber(*v->getDirection())] += *v->getColour();
}

void EmptyBlock::clear() {
	for (int i = 0; i < 4; i++) {
		vectors[i] = Colour::COLOUR_BLACK;
		vectors[i + 4] = Colour::COLOUR_BLACK;
	}
}

list<Vector*> EmptyBlock::getLight(Vector* from) {
	addVector(from);
	RelativePoint* next = new RelativePoint((*this->getPosition())*(*from->getDirection()));
	if (next->getX() <= 15 && next->getX() >= 0 && next->getY() <= 15 && next->getY() >= 0) {
		Vector* v = new Vector(*from, next);
		delete from;
		return list<Vector*>{v};
	}
	delete from;
	return list<Vector*>{};
}