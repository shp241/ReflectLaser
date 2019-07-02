#include"Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p) {
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

Point& Point::operator=(const Point& p) {
	this->x = p.x;
	this->y = p.y;
	return *this;
}

Point Point::operator*(Direction d) {
	return Point(this->x += d.getX(), this->y += d.getY());
}

Direction Direction::UP = Direction(0, 1);
Direction Direction::UP_RIGHT = Direction(1, 1);
Direction Direction::RIGHT = Direction(1, 0);
Direction Direction::DOWN_RIGHT = Direction(-1, 1);
Direction Direction::DOWN = Direction(0, -1);
Direction Direction::DOWN_LEFT = Direction(-1, -1);
Direction Direction::LEFT = Direction(-1, 0);
Direction Direction::UP_LEFT = Direction(-1, 1);

Direction::Direction(const Direction& d) {
	this->x = d.x;
	this->y = d.y;
}

Direction::Direction(int x, int y) {
	this->x = x;
	this->y = y;
}

int Direction::getX() {
	return x;
}

int Direction::getY() {
	return y;
}