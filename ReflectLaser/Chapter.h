#pragma once
#include"Button.h"

class Chapter :public Button {//关卡按钮点击
private:
	int chapters;//关卡编号
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role(Picture* p);
};