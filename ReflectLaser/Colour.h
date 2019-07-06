#pragma once

class Colour {//��ɫ��
private:
	bool R, G, B;
	static Colour colours[8];
public:
	static Colour RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, BLACK, WHITE;//һ���ܱ�ʾ��8����ɫ
	static int getColourNumber(Colour d);
	static Colour getNumberColour(int i);
	Colour(bool r = false, bool g = false, bool b = false);
	bool operator==(Colour c);
	Colour operator+(Colour c);
	void operator+=(Colour c);
	int getComplexity()const;
};
