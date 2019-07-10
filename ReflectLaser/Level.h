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
	Level(const Level& l);
	Map* getMap()const;
	Block* getBlock(RelativePoint p)const;
	Item* getItem(int i)const;
	Item* getCache()const;
	void setItem(int i, Item* it);
	void setCache(Item* it);
	void clear();//��չؿ�����
	void clearCache();//��ջ���
	void draw();//���ƹؿ�
	void addTarget(Target* t);//���Ŀ��
	void addEmitter(Emitter* e);//��ӷ�����
	bool isWin();//����Ƿ��ʤ
	void clearBlock(RelativePoint* p);//�����������
	void setBlock(RelativePoint* p, Block* b);//�ı䷽������
	~Level();
};

class FileException : public exception {//�����ļ�����
private:
	bool isIn;
public:
	FileException(bool in);
	const char * what() const throw ();
};