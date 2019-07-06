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

Level::Level(string name) {
	ifstream file(name + ".dat", ios::in | ios::binary);
	if (!file) {
		throw FileException(true);
		new(this)Level();
	}
	else {
		Level l;
		file.read((char*)&l, sizeof(l));
		new(this)Level(l);
	}
	file.close();
}

Level::Level(const Level& l) {
	this->game = new Map(*l.getMap());
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(*l.getItem(i));
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

void Level::saveFile(string name) {
	ofstream file(name + ".dat", ios::out | ios::binary);
	if (!file) {
		throw FileException(false);
	}
	else {
		file.write((char*)this, sizeof(*this));
	}
	file.close();
}

FileException::FileException(bool in) {
	this->isIn = in;
}

const char * FileException::what() const throw () {
	return isIn ? "Error in reading file." : "Error in writing file.";
}