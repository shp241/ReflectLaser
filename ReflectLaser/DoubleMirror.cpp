#include "DoubleMirror.h"

DoubleMirror::DoubleMirror(RelativePoint* p, int angle) :Item(p, false, angle) {}

void DoubleMirror::draw()const {
	Picture::putPicture("DoubleMirror_" + to_string(this->getAngle()),
		*getPosition()->getActualPoint());
	for (int i = 0; i < 8; i++) {
		Vector* v = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(getVectorColour(i)), new RelativePoint(*getPosition()));
		Picture::drawVector(v);
		delete v;
	}
}

list<Vector*> DoubleMirror::getLight(Vector* from) {
	Direction* direction[2];
	direction[0] = from->getDirection();
	int angle1 = this->getAngle();
	int angle2 = Direction::getDirectionNumber(*from->getDirection());
	if (angle1 % 4 == angle2 % 4) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector(angle2, from->getColour());
		RelativePoint* next = new RelativePoint((*this->getPosition())*(*from->getDirection()));
		if (next->getX() < 15 && next->getX() >= 0 && next->getY() < 15 && next->getY() >= 0) {
			Vector* v = new Vector(*from, next);
			return list<Vector*>{v};
		}
		return list<Vector*>{};
	}
	else if (angle1 % 4 == (angle2 + 2) % 4) {
		return list<Vector*>{};
	}
	else if (angle1 % 4 == (angle2 + 3) % 4) {
		addVector((angle2 + 4) % 8, from->getColour());
		addVector(angle2, from->getColour());
		addVector((angle2 + 2) % 8, from->getColour());
		direction[1] = new Direction(from->getDirection()->rotate(90));
	}
	else {//if (angle1 % 4 == (angle2 + 1) % 4)
		addVector((angle2 + 4) % 8, from->getColour());
		addVector(angle2, from->getColour());
		addVector((angle2 + 6) % 8, from->getColour());
		direction[1] = new Direction(from->getDirection()->rotate(-90));
	}
	list<Vector*> vectors = {};
	RelativePoint* next[2] = { new RelativePoint((*this->getPosition())*(*from->getDirection())) ,
		new RelativePoint((*this->getPosition())*(*direction[1])) };
	for (int i = 0; i < 2; i++) {
		if (next[i]->getX() < 15 && next[i]->getX() >= 0 && next[i]->getY() < 15 && next[i]->getY() >= 0) {
			Vector* v = new Vector(direction[i], from->getColour(), next[i]);
			vectors.push_back(v);
		}
	}
	return vectors;
}