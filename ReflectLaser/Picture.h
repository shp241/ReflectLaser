#pragma once
#include <easyx.h>
#include "Point.h"
#include <string>
#include <map>
using std::string;
using std::map;

class Picture {//用于加载图片和放置图片
private:
	static map<string, IMAGE*> loaded;
public:
	Picture(int w = 800, int h = 600);
	void putPicture(string picture, Point p = Point(0, 0));//在p位置放置名称为picture的图片
	void loadPictrue(string filename);//加载名称为picture的图片
	~Picture();
};