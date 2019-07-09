#include "Block.h"

Block::Block(RelativePoint* p, bool empty, bool moved) {
	this->p = new RelativePoint(*p);
	this->empty = empty;
	clear();
}

RelativePoint* Block::getPosition()const {
	return this->p;
}

Block::Block(const Block& b) {
	this->p = new RelativePoint(*b.p);
}

void Block::setPosition(RelativePoint* p) {
	this->p = new RelativePoint(*p);
}

bool Block::isEmpty()const {
	return empty;
}

bool Block::canMove()const {
	return moved;
}

string Block::getImage()const {
	return "Block\\EmptyBlock";
}

list<Vector*> Block::getLight(Vector* from) {
	if (empty) {
		addVector(from);
		RelativePoint* next = new RelativePoint((*this->getPosition())*(*from->getDirection()));
		if (next->getX() <= 15 && next->getX() >= 0 && next->getY() <= 15 && next->getY() >= 0) {
			Vector* v = new Vector(*from, next);
			delete from;
			return list<Vector*>{v};
		}
	}
	delete from;
	return list<Vector*>{};
}

Colour& Block::operator[](int n) {
	return vectors[n];
}

Colour Block::getVectorColour(int n)const {
	return vectors[n];
}

void Block::addVector(Vector* v) {
	vectors[Direction::getDirectionNumber(*v->getDirection())] += *v->getColour();
}

void Block::clear() {
	for (int i = 0; i < 4; i++) {
		vectors[i] = Colour::COLOUR_BLACK;
		vectors[i + 4] = Colour::COLOUR_BLACK;
	}
}

Block::~Block() {
	delete p;
}