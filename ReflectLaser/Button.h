#pragma once
#include "Point.h"
#include "Picture.h"
#include <graphics.h>

class Button {
private:
	Point* p0, *p1;//按钮矩形区域的两个对角顶点（顺时针）
public:
	Button() = default;
	Button(Point* p0, Point* p1);
	Button(Button& b);
	bool ifClick(int x, int y);//判断按钮是否被点击
	Point* getP(int n)const;//getter
	void setP(int n, Point* p);//setter
	Button& operator=(Button b);
	virtual void role(Picture* p);//虚函数role，由Start、Option、Help等等子类覆写
	~Button();
};