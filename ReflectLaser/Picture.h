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
	static bool opening;//标志是否已加载窗口
	static void open(int w = 800, int h = 600);//打开窗口
	static void putPicture(string picture, Point p = Point(0, 0));//在p位置放置名称为picture的图片，若未加载则进行加载
	static void loadPictrue(string filename);//加载名称为picture的图片
	static void close();//关闭窗口
};