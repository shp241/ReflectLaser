#include "Block.h"

Block::Block(RelativePoint* p, bool empty, bool moving) :Button(new Point(*p->getActualPoint()), new Point(p->getActualPoint()->getX() + 40, p->getActualPoint()->getY() + 40)) {
	this->p = new RelativePoint(*p);
	this->empty = empty;
	this->moving = moving;
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
	return moving;
}

string Block::getImage()const {
	return "emptyBlock";
}

void Block::role() {}

Block::~Block() {
	delete p;
}