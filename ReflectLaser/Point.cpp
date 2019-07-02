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

int cos(int angle){
    if(angle%180==90){
	return 0;
    }else if((angle-90)%360<=180){
	return -1;
    }else {
	return 1;
    }
}

int sin(int angle){
    return cos(angle+90);
}

Direction Direction::rotate(int angle){
    this->x=x*cos(angle)-y*sin(angle);
    this->y=x*sin(angle)+y*cos(angle);
}    
