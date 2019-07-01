#pragma once
class Point {
private:
	int x, y;
public:
	int getX();
	int getY();
	Point(int x = 0, int y = 0);
	void setX(int x);
	void setY(int y);
};