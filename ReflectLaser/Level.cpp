#include "Level.h"

Level::Level() {
	game = new Map();
	for (int i = 0; i < 24; i++) {
		items[i] = new Item(new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(Map* m, Item* it[], int n) {
	game = m;
	for (int i = 0; i < n; i++) {
		items[i] = it[i];
		items[i]->setPosition(new RelativePoint(15, i));
	}
	for (int i = n; i < 24; i++) {
		items[i] = new Item(new RelativePoint(15, i));
	}
	cache = new Item(new RelativePoint(-1, 0));
}

Level::Level(const Level& l) {
	this->game = new Map(*l.getMap());
	for (int i = 0; i < 24; i++) {
		items[i] = l.getItem(i);
	}
	this->cache = l.getCache();
	this->emitters = l.emitters;
	this->targets = l.targets;
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

Block* Level::getBlock(RelativePoint p)const {
	return (*game)[p];
}

void Level::setItem(int i, Item* it) {
	items[i] = it;
	it->setPosition(new RelativePoint(15, i));
}

void Level::setCache(Item* it) {
	cache = it;
	cache->setPosition(new RelativePoint(-1, 0));
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
	cache = new Item(new RelativePoint(-1, 0));
}

void Level::draw() {
	list<Emitter*>::iterator it;
	for (it = emitters.begin(); it != emitters.end(); ++it) {
		RelativePoint* next = new RelativePoint((*(*it)->getVector()->getPosition())*(*(*it)->getVector()->getDirection()));
		if (next->getX() < 15 && next->getX() >= 0 && next->getY() < 15 && next->getY() >= 0) {
			Vector * v = new Vector(*(*it)->getVector(), next);
			game->light(list<Vector*>{v});
		}
	}
	game->clearUsed();
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
		wined = wined && (*it)->isSucceeded();
	}
	return wined;
}

void Level::clearBlock(RelativePoint* p) {
	if (p->getX() == 15) {
		items[p->getY()] = new Item(new RelativePoint(15, p->getY()));
	}
	else if (p->getX() == -1) {
		clearCache();
	}
	else {
		game->clearBlock(p);
	}
}

void Level::setBlock(RelativePoint* p, Block* b) {
	if (p->getX() == 15) {
		setItem(p->getY(), dynamic_cast<Item*>(b));
	}
	else if (p->getX() == -1) {
		setCache(dynamic_cast<Item*>(b));
	}
	else {
		game->change(p, b);
	}
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