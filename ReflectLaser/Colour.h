#pragma once
#include <easyx.h>

class Colour {//��ɫ��
private:
	bool R, G, B;
	static Colour colours[8];
public:
	static Colour COLOUR_RED, COLOUR_GREEN, COLOUR_BLUE, COLOUR_CYAN, COLOUR_YELLOW, COLOUR_MAGENTA, COLOUR_BLACK, COLOUR_WHITE;//һ���ܱ�ʾ��8����ɫ
	static int getColourNumber(Colour* d);
	static Colour getNumberColour(int i);
	Colour(bool r = false, bool g = false, bool b = false);
	bool operator==(Colour c);
	Colour operator+(Colour c)const;
	void operator+=(Colour c);
	int getComplexity()const;
	COLORREF getColor()const;
	bool isBlack()const;
};
