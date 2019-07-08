#pragma once

class Point {//点类
private:
	int x, y;
public:
	Point(int x = 0, int y = 0);
	Point(const Point& p);
	int getX()const;
	int getY()const;
	void setX(int x);
	void setY(int y);
	Point& operator=(const Point& p);
};

class Direction {//方向类
private:
	int x, y;
	static Direction directions[8];
public:
	static Direction UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT;//8个基础方向
	static int getDirectionNumber(Direction d);
	static Direction getNumberDirection(int i);
	Direction(int x, int y);
	Direction(const Direction& d);
	int getX()const;
	int getY()const;
	Direction rotate(int angle = 45);//将方向旋转angle度数后得到的方向
	bool operator==(Direction& d);
};
