#pragma once
#include "Point.h"

class RelativePoint : public Point {//���ڱ�ʾ��ͼ�п�����λ��(0,0)~(14,14)
public:
	RelativePoint(int x = 0, int y = 0);
	RelativePoint(const RelativePoint& p);
	RelativePoint operator*(Direction d);//������Է����Ի�ø÷�������һ���������
	Point* getActualPoint();
};
