#pragma once
#include"point.h"
#include<graphics.h>

class Button {
private:
	Point* p1, *p2;//按钮矩形区域的两个对角顶点（顺时针）
public:
	Button(Point* p1, Point* p2);

	bool if_click(int x, int y);
};