#include "Wall.h"

Wall::Wall(RelativePoint* p) :Block(p) {}

string Wall::getImage()const {
	return "Block\\Wall";
}

list<Vector*> Wall::getLight(Vector* from) {
	return list<Vector*>{};
}