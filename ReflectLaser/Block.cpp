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

void Block::draw()const {
	Picture::putPicture("Block\\EmptyBlock", *p->getActualPoint());
	if (empty) {
		for (int i = 0; i < 4; i++) {
			Vector* v0 = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(vectors[i] + vectors[i + 4]), new RelativePoint(*p));
			Vector* v1 = new Vector(new Direction(Direction::getNumberDirection(i).rotate(180)), new Colour(vectors[i] + vectors[i + 4]), new RelativePoint(*p));
			Picture::drawVector(v0);
			Picture::drawVector(v1);
			delete v0;
			delete v1;
		}
	}
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