#pragma once
#include "EmptyBlock.h"

class Map {//���ڴ�ŵ�ͼ������
private:
	Block* game[15][15];
public:
	Map();
	Map(const Map& m);
	Block* operator[](RelativePoint p)const;//����Blockָ��
	void change(RelativePoint* p, Block* b);//�ı�ĳһ������ݣ����ı����꣩
	~Map();
};