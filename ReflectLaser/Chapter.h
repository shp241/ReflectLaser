#pragma once
#include"Button.h"

class Chapter :public Button {
private:
	int chapters;//¹Ø¿¨±àºÅ
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role(Picture* p);
};