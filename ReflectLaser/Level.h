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

class Level {//���ڴ�Źؿ����ݣ�������ͼ�͵��ߣ�
private:
	Map* game;
	Item* items[24];
	Item* cache;
	list<Target*> targets = {};
	list<Emitter*> emitters = {};
public:
	Level();
	Level(Map* m, Item* it[], int n);//nΪ������Ԫ�ظ���
	Level(string name);//���ļ��м���
	Level(const Level& l);
	Map* getMap()const;
	Item* getItem(int i)const;
	Item* getCache()const;
	void setItem(int i, Item* it);
	void setCache(Item* it);
	void saveFile(string name);//���浽�ļ�
	void clear();//��չؿ�����
	void clearCache();//��ջ���
	void draw();//���ƹؿ�
	void addTarget(Target* t);//���Ŀ��
	void addEmitter(Emitter* e);//��ӷ�����
	bool isWin();//����Ƿ��ʤ
	~Level();
};

class FileException : public exception {//�����ļ�����
private:
	bool isIn;
public:
	FileException(bool in);
	const char * what() const throw ();
};