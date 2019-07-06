#pragma once
#include <easyx.h>
#include <map>
#include <string>
#include "Point.h"
using std::map;
using std::string;

class Picture {//用于加载图片和放置图片
private:
	static map<string, IMAGE*> loaded;//用于存放已加载的图片
public:
	Picture(int w = 800, int h = 600);
	void putPicture(string picture, Point p = Point(0, 0));//在p位置放置名称为picture的图片，若未加载则进行加载
	void loadPictrue(string filename);//加载名称为picture的图片
	~Picture();
};