#pragma once
#include <list>
#include <iostream>
#include <string>
#include "RelativePoint.h"
#include "Vector.h"
using std::list;
using std::string;
using std::to_string;

class Block {//单一地图块类
private:
	RelativePoint* p;//地图块的相对坐标
	bool empty;//ture则表示该地图块为空
	bool moved;//ture则表示该地图块可移动
public:
	Block(RelativePoint* p, bool empty = true, bool moved = false);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//判断该地图块是否为空
	bool canMove()const;//判断该地图块是否可移动
	virtual string getImage()const;//获取该地图块上道具的图片名
	virtual list<Vector*> getLight(Vector* from);
	virtual ~Block();
};
