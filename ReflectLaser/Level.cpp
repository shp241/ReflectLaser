#include "Level.h"

Level::Level() {
	game = new Map();
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(Map* m, Item* it[]) {
	game = new Map(*m);
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(*it[i], new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(string name) {
	ifstream file("Level\\" + name + ".dat", ios::in | ios::binary);
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
	this->cache = new Item(*l.getCache());
}

Map* Level::getMap()const {
	return this->game;
}

Item* Level::getItem(int i)const {
	return items[i];
}

Item* Level::getCache()const {
	return cache;
}

void Level::setItem(int i, Item* it) {
	items[i] = new Item(*it);
}

void Level::setCache(Item* it) {
	cache = new Item(*it, new RelativePoint(-1, 0));
}

void Level::saveFile(string name) {
	ofstream file("Level\\" + name + ".dat", ios::out | ios::binary);
	if (!file) {
		throw FileException(false);
	}
	else {
		file.write((char*)this, sizeof(*this));
	}
	file.close();
}

void Level::clear() {
	delete game;
	game = new Map();
	for (int i = 0; i < 24; i++) {
		delete items[i];
		items[i] = new Item(false);
	}
}

void Level::clearCache() {
	delete cache;
	cache = new Item(new RelativePoint(-1, 0));
}

Level::~Level() {
	delete game;
	for (int i = 0; i < 24; i++) {
		delete items[i];
	}
	delete items;
}

FileException::FileException(bool in) {
	this->isIn = in;
}

const char * FileException::what() const throw () {
	return isIn ? "Error in reading file." : "Error in writing file.";
}