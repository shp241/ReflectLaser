#include"Button.h"
#include<graphics.h>

Button::Button(Point* p1, Point* p2) {
	this->p1 = p1;
	this->p2 = p2;
}

bool Button::if_click(int x, int y) {
	return x >= p1->getX() && x <= p2->getX() && y >= p1->getY() && y <= p2->getY;
}