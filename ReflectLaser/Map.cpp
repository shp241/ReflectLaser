#include "Map.h"

Map::Map() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			game[i][j] = new EmptyBlock(new RelativePoint(i, j));
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
}