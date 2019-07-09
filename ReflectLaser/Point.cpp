#include "Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p) {
	this->x = p.x;
	this->y = p.y;
}

int Point::getX()const {
	return x;
}

int Point::getY()const {
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

Direction Direction::UP = Direction(0, -1);
Direction Direction::UP_RIGHT = Direction(1, -1);
Direction Direction::RIGHT = Direction(1, 0);
Direction Direction::DOWN_RIGHT = Direction(1, 1);
Direction Direction::DOWN = Direction(0, 1);
Direction Direction::DOWN_LEFT = Direction(-1, 1);
Direction Direction::LEFT = Direction(-1, 0);
Direction Direction::UP_LEFT = Direction(-1, -1);
Direction Direction::directions[] = { UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT };

Direction::Direction(const Direction& d) {
	this->x = d.x;
	this->y = d.y;
}

Direction::Direction(int x, int y) {
	this->x = x;
	this->y = y;
}

Direction::Direction(int angle) {
	this->x = getNumberDirection(angle).x;
	this->y = getNumberDirection(angle).y;
}

int Direction::getX()const {
	return x;
}

int Direction::getY()const {
	return y;
}

Direction Direction::rotate(int angle) {
	return Direction(getDirectionNumber(*this)+angle/45);
}

bool Direction::operator==(Direction& d) {
	return d.getX() == this->x&&d.getY() == this->y;
}

int Direction::getDirectionNumber(Direction d) {
	for (int i = 0; i < 8; i++) {
		if (directions[i] == d) {
			return i;
		}
	}
	return 0;
}
Direction Direction::getNumberDirection(int i) {
	return directions[(i+8) % 8];
}