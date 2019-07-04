#include "Block.h"

Block::Block(RelativePoint* p) {
	this->p = p;
}

RelativePoint* Block::getPosition() {
	return this->p;
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