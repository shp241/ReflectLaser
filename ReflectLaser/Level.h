#pragma once
#include <exception>
#include <fstream>
#include "Item.h"
#include "Map.h"
using std::exception;
using std::ifstream;
using std::ios;
using std::ofstream;

class Level {//���ڴ�Źؿ����ݣ�������ͼ�͵��ߣ�
private:
	Map* game;
	Item* items[24];
public:
	Level();
	Level(Map* m, Item* it[]);
	Level(string name);//���ļ��м���
	Level(const Level& l);
	Map* getMap()const;
	Item* getItem(int i)const;
	void setItem(int i, Item* it);
	void saveFile(string name);//���浽�ļ�
	~Level();
};

class FileException : public exception {//�����ļ�����
private:
	bool isIn;
public:
	FileException(bool in);
	const char * what() const throw ();
};