#include "Item.h"

Item::Item(RelativePoint* p, bool empty, int angle) :Block(p, empty, true) {
	this->angle = angle;
}

Item::Item(const Item& it) : Block(it.getPosition(), it.isEmpty()) {
	this->angle = it.angle;
}

Item::Item(const Item& it, RelativePoint* p) : Block(p, it.isEmpty()) {
	this->angle = it.angle;
}

void Item::rotate(bool isClock) {
	this->angle = (this->angle + isClock ? 1 : -1) % 8;
}

int Item::getAngle()const {
	return angle;
}

void Item::setAngle(int angle) {
	this->angle = angle;
}

string Item::getImage()const {
	return "Block\\EmptyBlock";
}

list<Vector*> Item::getLight(Vector* from) {
	return list<Vector*>{};
}

Item::~Item() {}