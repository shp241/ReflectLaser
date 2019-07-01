#pragma once
#include"Point.h"
#include<graphics.h>

class Button {
private:
	Point* p0, *p1;//按钮矩形区域的两个对角顶点（顺时针）
public:
	Button(Point* p0, Point* p1);
	Button(Button& b);
	bool ifClick(int x, int y);
	Point* getP(int n);
	void setP(int n,Point* p);
	Button& operator=(Button b);
	~Button();
};