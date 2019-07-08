#include "Mirror.h"

Mirror::Mirror(RelativePoint* p, int angle) :Item(p, false, angle) {}

string Mirror::getImage()const {
	return "Block\\Item\\Mirror\\Mirror_" + to_string(this->getAngle());
}

list<Vector*> Mirror::getLight(Vector* from) {
	Direction* direction;
	int angle1 = this->getAngle();
	int angle2 = Direction::getDirectionNumber(*from->getDirection());
	if (angle1 == (angle2 + 4) % 8) {
		direction = new Direction(from->getDirection()->rotate(180));
	}
	else if (angle1 == (angle2 + 3) % 8) {
		direction = new Direction(from->getDirection()->rotate(-90));
	}
	else if (angle1 == (angle2 + 5) % 8) {
		direction = new Direction(from->getDirection()->rotate(90));
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