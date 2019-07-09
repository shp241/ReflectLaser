#pragma once
#include "Block.h"
#include "Picture.h"

class Map {//用于存放地图块数组
private:
	Block* game[15][15];
public:
	Map();
	Map(const Map& m);
	Block* operator[](RelativePoint p)const;//返回Block指针
	void change(RelativePoint* p, Block* b);//改变某一块的内容（不改变坐标）
	void clearBlock(RelativePoint* p);
	void draw();
	list<Vector*> light(list<Vector*> from);//光线传导
	~Map();
};