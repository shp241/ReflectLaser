#pragma once
class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0);
	Point(const Point& p);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Point& operator=(const Point& p);
	Point operator*(Direction d);
};

class Direction {
private:
	int x, y;
public:
	static Direction UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT;
	Direction(int x, int y);
	Direction(const Direction& d);
	int getX();
	int getY();
};