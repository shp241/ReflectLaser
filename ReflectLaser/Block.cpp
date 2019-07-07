#include "Block.h"

Block::Block(RelativePoint* p, bool empty, bool moving) {
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

Block::~Block() {
	delete p;
}