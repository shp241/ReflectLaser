#include "Block.h"

Block::Block(RelativePoint* p) {
	this->p = p;
}

RelativePoint* Block::getPosition()const {
	return this->p;
}

void Block::setPosition(RelativePoint* p) {
	this->p = new RelativePoint(p);
}

bool Block::isEmpty() {
	return true;
}

bool Block::canMove() {
	return false;
}

void Block::draw() {
	//
}

Block::~Block() {
	delete p;
}