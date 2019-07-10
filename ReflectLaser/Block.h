#pragma once
#include <list>
#include <iostream>
#include <string>
#include "RelativePoint.h"
#include "Picture.h"
#include "Vector.h"
using std::list;
using std::string;
using std::to_string;

class Block {//单一地图块类
private:
	RelativePoint* p;//地图块的相对坐标
	bool empty;//ture则表示该地图块为空
	bool moved;//ture则表示该地图块可移动
	Colour vectors[8];//存放8个方向的向量的颜色
public:
	Block(RelativePoint* p, bool empty = true, bool moved = true);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//判断该地图块是否为空
	bool canMove()const;//判断该地图块是否可移动
	void addVector(Vector* v);//向空地图块中添加向量
	void addVector(int angle, Colour* colour);
	void clear();//清空所有向量
	Colour& operator[](int n);//获取向量组中的元素
	Colour getVectorColour(int n)const;//获取向量组中的元素
	virtual void draw()const;//获取该地图块上道具的图片名
	virtual list<Vector*> getLight(Vector* from);
	virtual ~Block();
};
