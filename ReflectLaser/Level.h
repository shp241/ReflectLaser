#pragma once
#include <exception>
#include <fstream>
#include <list>
#include "Emitter.h"
#include "Item.h"
#include "Map.h"
#include "Target.h"
using std::exception;
using std::ifstream;
using std::ios;
using std::list;
using std::ofstream;

class Level {//用于存放关卡数据（包括地图和道具）
private:
	Map* game;
	Item* items[24];
	Item* cache;
	list<Target*> targets = {};
	list<Emitter*> emitters = {};
public:
	Level();
	Level(Map* m, Item* it[], int n);//n为数组中元素个数
	Level(string name);//从文件中加载
	Level(const Level& l);
	Map* getMap()const;
	Item* getItem(int i)const;
	Item* getCache()const;
	void setItem(int i, Item* it);
	void setCache(Item* it);
	void saveFile(string name);//保存到文件
	void clear();//清空关卡数据
	void clearCache();//清空缓存
	void draw();//绘制关卡
	void addTarget(Target* t);//添加目标
	void addEmitter(Emitter* e);//添加发射器
	bool isWin();//检测是否获胜
	~Level();
};

class FileException : public exception {//用于文件报错
private:
	bool isIn;
public:
	FileException(bool in);
	const char * what() const throw ();
};