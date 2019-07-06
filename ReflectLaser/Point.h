#pragma once

class Point {//����
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

class Direction {//������
private:
	int x, y;
public:
	static Direction UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT;//8����������
	Direction(int x, int y);
	Direction(const Direction& d);
	int getX()const;
	int getY()const;
	Direction rotate(int angle = 45);//��������תangle������õ��ķ���
	bool operator==(Direction& d);
};
