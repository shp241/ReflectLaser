#pragma once
#include"Button.h"

class Chapter :public Button {
private:
	int chapters;//指定为第几关
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role(Picture* p);
};