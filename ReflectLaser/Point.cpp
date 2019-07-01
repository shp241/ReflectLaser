#include"Point.h"
int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}