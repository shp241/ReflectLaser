#include "Block.h"

Block::Block(RelativePoint* p) {
	this->p = new RelativePoint(*p);
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

bool Block::isEmpty() {
	return true;
}

bool Block::canMove() {
	return false;
}

string Block::getImage() {
	return "emptyBlock";
}

Block::~Block() {
	delete p;
}