<<<<<<< HEAD
#include "Block.h"

Block::Block(RelativePoint* p, bool empty) :Button(new Point(*p->getActualPoint()), new Point(p->getActualPoint()->getX() + 40, p->getActualPoint()->getY() + 40)) {
	this->p = new RelativePoint(*p);
	this->empty = empty;
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

string Block::getImage()const {
	return "emptyBlock";
}

void Block::role() {}

Block::~Block() {
	delete p;
=======
#include "Block.h"

Block::Block(RelativePoint* p, bool empty) :Button(new Point(*p->getActualPoint()), new Point(p->getActualPoint()->getX() + 40, p->getActualPoint()->getY() + 40)) {
	this->p = new RelativePoint(*p);
	this->empty = empty;
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

string Block::getImage()const {
	return "emptyBlock";
}

void Block::role() {}

Block::~Block() {
	delete p;
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
}