#include "Item.h"

Item::Item(RelativePoint* p, bool empty, int angle) :Block(p, empty, true) {
	this->angle = angle;
}

Item::Item(const Item& it) : Block(it.getPosition(), it.isEmpty(), true) {
	this->angle = it.angle;
}

void Item::rotate(bool isClock) {
	this->angle = (this->angle + (isClock ? 1 : 7)) % 8;
}

int Item::getAngle()const {
	return angle;
}

void Item::setAngle(int angle) {
	this->angle = angle;
}

void Item::draw()const {
	Point p = *getPosition()->getActualPoint();
	Picture::putPicture("EmptyBlock", p);
	if (isEmpty()) {
		for (int i = 0; i < 4; i++) {
			Vector* v0 = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(getVectorColour(i) + getVectorColour(i + 4)), new RelativePoint(*getPosition()));
			Vector* v1 = new Vector(new Direction(Direction::getNumberDirection(i).rotate(180)), new Colour(getVectorColour(i) + getVectorColour(i + 4)), new RelativePoint(*getPosition()));
			Picture::drawVector(v0);
			Picture::drawVector(v1);
			delete v0;
			delete v1;
		}
	}
}

list<Vector*> Item::getLight(Vector* from) {
	return list<Vector*>{};
}

Item::~Item() {}