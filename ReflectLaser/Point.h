#pragma once
class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0);
	Point(Point& p);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Point& operator=(Point& p);
};