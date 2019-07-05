#include "Button.h"
#include<graphics.h>

Button::Button(Point* p0, Point* p1) {
	this->p0 = p0;
	this->p1 = p1;
}

Button::Button(Button& b) {
	this->p0 = new Point(*b.p0);
	this->p1 = new Point(*b.p1);
}

bool Button::ifClick(int x, int y) {
	return x >= p0->getX() && x <= p1->getX() && y >= p0->getY() && y <= p1->getY;
}

Point* Button::getP(int n)const {
	if (n == 0) {
		return p0;
	}
	else {
		return p1;
	}
}

void Button::setP(int n, Point* p) {
	if (n == 0) {
		p0 = p;
	}
	else {
		p1 = p;
	}
}

Button& Button::operator=(Button b) {
	this->p0 = new Point(*b.p0);
	this->p1 = new Point(*b.p1);
	return *this;
}

void Button::role() {

}

Button::~Button() {
	delete p0;
	delete p1;
}