#include "RelativePoint.h"

RelativePoint::RelativePoint(int x, int y) :Point(x, y) {}

RelativePoint RelativePoint::operator*(Direction d) {
	return RelativePoint(this->getX() + d.getX(), this->getY() + d.getY());
}

RelativePoint::RelativePoint(const RelativePoint& p) {
	this->setX(p.getX());
	this->setY(p.getY());
}

Point* RelativePoint::getActualPoint() {
	if (this->getX() == 15) {
		return new Point(620 + 40 * (this->getY() / 4), 40 + 40 * (this->getY() % 4));
	}
	else if (this->getX() == -1) {
		return new Point(680, 320);
	}
	else {
		return new Point(40 * this->getX(), 40 * this->getY());
	}
}