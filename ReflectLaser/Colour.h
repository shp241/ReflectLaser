#pragma once
class Colour {
private:
	bool R, G, B;
public:
	Colour(bool r = false, bool g = false, bool b = false);
	bool operator==(Colour c);
	Colour operator+(Colour c);
	int getComplexity();
};