#pragma once
#include"Button.h"

class Chapter :public Button {//�ؿ���ť���
private:
	int chapters;//�ؿ����
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role(Picture* p);
};