#pragma once
#include"point.h"
#include<graphics.h>

class Button {
private:
	Point* p1, *p2;//��ť��������������ԽǶ��㣨˳ʱ�룩
public:
	Button(Point* p1, Point* p2);

	bool if_click(int x, int y);
};