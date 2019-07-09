#include "Level.h"

Level::Level() {
	game = new Map();
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(Map* m, Item* it[], int n) {
	game = new Map(*m);
	for (int i = 0; i < n; i++) {
		items[i] = new Item(*it[i], new RelativePoint(15, i));
	}
	for (int i = n; i < 24; i++) {
		items[i] = new Item(new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(string name) {
	ifstream file("Level\\" + name + ".dat", ios::in | ios::binary);
	if (!file) {
		new(this)Level();
	}
	else {
		Level* l=new Level();
		file.read(reinterpret_cast<char *>(l), sizeof(Level));
		new(this)Level(*l);
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
		file.write(reinterpret_cast<char *>(this), sizeof(Level));
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

void Level::draw() {
	list<Emitter*>::iterator it;
	for (it = emitters.begin(); it != emitters.end(); ++it) {
		RelativePoint* next = new RelativePoint((*(*it)->getVector()->getPosition())*(*(*it)->getVector()->getDirection()));
		if (next->getX() <= 15 && next->getX() >= 0 && next->getY() <= 15 && next->getY() >= 0) {
			Vector * v = new Vector(*(*it)->getVector(), next);
			game->light(list<Vector*>{v});
			delete v;
		}
	}
	game->draw();
	for (int i = 0; i < 24; i++) {
		items[i]->draw();
	}
	cache->draw();
}

void Level::addTarget(Target* t) {
	game->change(t->getPosition(), t);
	targets.push_back(t);
}

void Level::addEmitter(Emitter* e) {
	game->change(e->getPosition(), e);
	emitters.push_back(e);
}

bool Level::isWin() {
	if (targets.size() == 0) {
		return false;
	}
	bool wined = true;
	list<Target*>::iterator it;
	for (it = targets.begin(); it != targets.end(); ++it) {
		wined && (*it)->isSucceeded();
	}
	return wined;
}

Level::~Level() {
	delete game;
	for (int i = 0; i < 24; i++) {
		delete items[i];
	}
}

FileException::FileException(bool in) {
	this->isIn = in;
}

const char * FileException::what() const throw () {
	return isIn ? "Error in reading file." : "Error in writing file.";
}