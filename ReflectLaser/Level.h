#pragma once
#include "Map.h"
#include "Item.h"
#include <fstream>
#include <exception>
using std::ofstream;
using std::ifstream;
using std::ios;
using std::exception;

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