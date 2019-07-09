#include "HalfMirror.h"

HalfMirror::HalfMirror(RelativePoint* p, int angle) :Item(p, false, angle) {}

void HalfMirror::draw()const {
	Picture::putPicture("Block\\Item\\HalfMirror\\HalfMirror_" + to_string(this->getAngle()),
		*getPosition()->getActualPoint());
	for (int i = 0; i < 8; i++) {
		Vector* v = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(getVectorColour(i)), new RelativePoint(*getPosition()));
		Picture::drawVector(v);
		delete v;
	}
}

list<Vector*> HalfMirror::getLight(Vector* from) {
	Direction* direction;
	int angle1 = this->getAngle();
	int angle2 = Direction::getDirectionNumber(*from->getDirection());
	if (angle1 == (angle2 + 3) % 8) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector((angle2 - 1) % 8, from->getColour());
		direction = new Direction(from->getDirection()->rotate(-45));
	}
	else if (angle1 == (angle2 + 4) % 8) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector((angle2 - 3) % 8, from->getColour());
		direction = new Direction(from->getDirection()->rotate(-135));
	}
	else if (angle1 == (angle2 + 5) % 8) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector((angle2 + 3) % 8, from->getColour());
		direction = new Direction(from->getDirection()->rotate(135));
	}
	else if (angle1 == (angle2 + 6) % 8) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector((angle2 + 1) % 8, from->getColour());
		direction = new Direction(from->getDirection()->rotate(45));
	}
	else {
		delete from;
		return list<Vector*>{};
	}
	RelativePoint* next = new RelativePoint((*this->getPosition())*(*direction));
	if (next->getX() <= 15 && next->getX() >= 0 && next->getY() <= 15 && next->getY() >= 0) {
		Vector* v = new Vector(direction, from->getColour(), next);
		delete from;
		return list<Vector*>{v};
	}
	delete from;
	return list<Vector*>{};
}