#pragma once

class Colour {//��ɫ��
private:
	bool R, G, B;
public:
	const static Colour RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, BLACK, WHITE;//һ���ܱ�ʾ��8����ɫ
	Colour(bool r = false, bool g = false, bool b = false);
	bool operator==(Colour c);
	Colour operator+(Colour c);
	void operator+=(Colour c);
	int getComplexity()const;
};
