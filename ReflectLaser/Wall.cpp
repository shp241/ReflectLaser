#include "Wall.h"

Wall::Wall(RelativePoint* p) :Block(p) {}

void Wall::draw()const {
	Picture::putPicture("Wall", *getPosition()->getActualPoint());
}

list<Vector*> Wall::getLight(Vector* from) {
	return list<Vector*>{};
}