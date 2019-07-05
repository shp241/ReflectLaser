#pragma once
#include "Map.h"
#include "Item.h"
class Level {
private:
	Map* game;
	Item* items[24];
public:
	Level();
	Level(Map* m, Item* it[]);
	Map* getMap()const;
	Item* getItem(int i)const;
	void setItem(int i, Item* it);
};