#pragma once
#include "Point.h"
#include<graphics.h>

class Button {
private:
	Point* p0, *p1;//��ť��������������ԽǶ��㣨˳ʱ�룩
public:
  Button() = default;
	Button(Point* p0, Point* p1);
	Button(Button& b);
	bool ifClick(int x, int y);
	Point* getP(int n)const;
	void setP(int n, Point* p);
	Button& operator=(Button b);
	virtual void role();
	~Button();
};