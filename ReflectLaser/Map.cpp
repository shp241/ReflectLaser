#include "Map.h"

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			game[i][j] = new Block(new RelativePoint(i, j));
		}
	}
}

Map::Map(const Map& m) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			game[i][j] = m[RelativePoint(i, j)];
		}
	}
}

Block* Map::operator[](RelativePoint p)const {
	return game[p.getX()][p.getY()];
}

void Map::change(RelativePoint* p, Block* b) {
	game[p->getX()][p->getY()] = new Block(*b);
	game[p->getX()][p->getY()]->setPosition(p);
}

void Map::clearBlock(RelativePoint* p) {
	delete game[p->getX()][p->getY()];
	game[p->getX()][p->getY()] = new Block(p);
}

void Map::draw() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			game[i][j]->draw();
		}
	}
}

list<Vector*> Map::light(list<Vector*> from) {
	list<Vector*>::iterator it;
	for (it = from.begin(); it != from.end(); ++it) {
		light(game[(*it)->getPosition()->getX()][(*it)->getPosition()->getY()]->getLight(*it));
	}
}

Map::~Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			delete game[i][j];
		}
	}
	delete game;
}