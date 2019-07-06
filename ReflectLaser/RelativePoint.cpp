#include "RelativePoint.h"

RelativePoint::RelativePoint(int x, int y) :Point(x, y) {}

RelativePoint RelativePoint::operator*(Direction d) {
	return RelativePoint(this->getX() + d.getX(), this->getY() + d.getY());
}

RelativePoint::RelativePoint(const RelativePoint& p) {
	this->setX(p.getX());
	this->setY(p.getY());
}