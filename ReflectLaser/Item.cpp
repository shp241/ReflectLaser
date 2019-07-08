#include "Item.h"

Item::Item(RelativePoint* p, bool empty) :Block(p, empty) {}

Item::Item(const Item& it) : Block(it.getPosition(), it.isEmpty(), it.canMove()) {
	this->angle = it.angle;
}

Item::Item(const Item& it, RelativePoint* p) : Block(p, it.isEmpty(), it.canMove()) {
	this->angle = it.angle;
}

void Item::rotate(bool isClock) {
	this->angle = (this->angle + isClock ? 1 : -1) % 8;
}

string Item::getImage()const {
	return "Block\\EmptyBlock";
}