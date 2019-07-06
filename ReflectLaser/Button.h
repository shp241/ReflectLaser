#pragma once
#include "Point.h"
#include "Picture.h"
#include <graphics.h>

class Button {
private:
	Point* p0, *p1;//��ť��������������ԽǶ��㣨˳ʱ�룩
public:
	Button() = default;
	Button(Point* p0, Point* p1);
	Button(Button& b);
	bool ifClick(int x, int y);//�жϰ�ť�Ƿ񱻵��
	Point* getP(int n)const;//getter
	void setP(int n, Point* p);//setter
	Button& operator=(Button b);
	virtual void role(Picture* p);//�麯��role����Start��Option��Help�ȵ����าд
	~Button();
};