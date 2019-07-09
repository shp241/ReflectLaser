#include "DoubleMirror.h"

DoubleMirror::DoubleMirror(RelativePoint* p, int angle) :Item(p, false, angle) {}

void DoubleMirror::draw()const {
	Picture::putPicture("Block\\Item\\DoubleMirror\\DoubleMirror_" + to_string(this->getAngle()),
		*getPosition()->getActualPoint());
	for (int i = 0; i < 8; i++) {
		Vector* v = new Vector(new Direction(Direction::getNumberDirection(i)), new Colour(getVectorColour(i)), new RelativePoint(*getPosition()));
		Picture::drawVector(v);
		delete v;
	}
}

list<Vector*> DoubleMirror::getLight(Vector* from) {
	Direction* direction;
	int angle1 = this->getAngle();
	int angle2 = Direction::getDirectionNumber(*from->getDirection());
	if (angle1 % 4 == angle2 % 4) {
		RelativePoint* next = new RelativePoint((*this->getPosition())*(*from->getDirection()));
		if (next->getX() <= 15 && next->getX() >= 0 && next->getY() <= 15 && next->getY() >= 0) {
			Vector* v = new Vector(*from, next);
			delete from;
			return list<Vector*>{v};
		}
		delete from;
		return list<Vector*>{};
	}
	else if (angle1 % 4 == (angle2 + 2) % 4) {
		delete from;
		return list<Vector*>{};
	}
	else if (angle1 % 4 == (angle2 + 3) % 4) {
		direction = new Direction(from->getDirection()->rotate(-90));
	}
	else if (angle1 % 4 == (angle2 + 1) % 4) {
		direction = new Direction(from->getDirection()->rotate(90));
	}
	list<Vector*> vectors = {};
	RelativePoint* next[2] = { new RelativePoint((*this->getPosition())*(*from->getDirection())) ,
		new RelativePoint((*this->getPosition())*(*direction)) };
	for (int i = 0; i < 2; i++) {
		if (next[i]->getX() <= 15 && next[i]->getX() >= 0 && next[i]->getY() <= 15 && next[i]->getY() >= 0) {
			Vector* v = new Vector(direction, from->getColour(), next[i]);
			vectors.push_back(v);
		}
	}
	delete from;
	return vectors;
}