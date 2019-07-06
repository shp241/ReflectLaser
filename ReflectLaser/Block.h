#pragma once
#include "RelativePoint.h"
#include <string>
using std::string;

class Block {//单一地图块类
private:
	RelativePoint* p;//地图块的相对坐标
	bool empty;//ture则表示该地图块为空
	bool moving;//ture则表示该地图块可移动
public:
	Block(RelativePoint* p, bool empty = true, bool moving = false);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty();//判断该地图块是否为空
	bool canMove();//判断该地图块是否能移动
	virtual string getImage();//获取该地图块上道具的图片名
	virtual ~Block();
};
