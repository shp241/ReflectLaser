#include"Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point(Point& p) {
	this->x = p.x;
	this->y = p.y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

Point& Point::operator=(Point& p) {
	this->x = p.x;
	this->y = p.y;
}