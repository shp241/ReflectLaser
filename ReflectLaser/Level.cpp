#include "Level.h"

Level::Level() {
	game = new Map();
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(false);
	}
}

Level::Level(Map* m, Item* it[]) {
	game = new Map(*m);
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(it[i]);
	}
}

Map* Level::getMap()const {
	return this->game;
}

Item* Level::getItem(int i)const {
	return items[i];
}

void Level::setItem(int i, Item* it) {
	items[i] = new Item(*it);
}