<<<<<<< HEAD
#include "Item.h"

Item::Item(RelativePoint* p, bool empty, int angle) :Block(p, empty) {
	this->angle = angle;
}

Item::Item(const Item& it) : Block(it.getPosition(), it.isEmpty(), it.canMove()) {
	this->angle = it.angle;
}

Item::Item(const Item& it, RelativePoint* p) : Block(p, it.isEmpty(), it.canMove()) {
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

void Item::role() {
	if (System::game->getCache()->isEmpty()) {
		System::game->setCache(new Item(*this));
		System::game->getMap()->clearBlock(this->getPosition());
	}
}

=======
#include "Item.h"

Item::Item(RelativePoint* p, bool empty, int angle) :Block(p, empty) {
	this->angle = angle;
}

Item::Item(const Item& it) : Block(it.getPosition(), it.isEmpty(), it.canMove()) {
	this->angle = it.angle;
}

Item::Item(const Item& it, RelativePoint* p) : Block(p, it.isEmpty(), it.canMove()) {
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

void Item::role() {
	if (System::game->getCache()->isEmpty()) {
		System::game->setCache(new Item(*this));
		System::game->getMap()->clearBlock(this->getPosition());
	}
}

>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
Item::~Item() {}