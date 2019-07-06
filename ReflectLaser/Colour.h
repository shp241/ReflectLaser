#pragma once

class Colour {//颜色类
private:
	bool R, G, B;
public:
	const static Colour RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, BLACK, WHITE;//一共能表示的8种颜色
	Colour(bool r = false, bool g = false, bool b = false);
	bool operator==(Colour c);
	Colour operator+(Colour c);
	void operator+=(Colour c);
	int getComplexity()const;
};
