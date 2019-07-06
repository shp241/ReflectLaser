#pragma once
#include "Map.h"
#include "Item.h"
#include <fstream>
#include <exception>
using std::ofstream;
using std::ifstream;
using std::ios;
using std::exception;

class Level {//用于存放关卡数据（包括地图和道具）
private:
	Map* game;
	Item* items[24];
public:
	Level();
	Level(Map* m, Item* it[]);
	Level(string name);//从文件中加载
	Level(const Level& l);
	Map* getMap()const;
	Item* getItem(int i)const;
	void setItem(int i, Item* it);
	void saveFile(string name);//保存到文件
	~Level();
};

class FileException : public exception {//用于文件报错
private:
	bool isIn;
public:
	FileException(bool in);
	const char * what() const throw ();
};