#pragma once
#include "Point.h"

class RelativePoint : public Point {//用于表示地图中块的相对位置(0,0)~(14,14)
public:
	RelativePoint(int x = 0, int y = 0);
	RelativePoint(const RelativePoint& p);
	RelativePoint operator*(Direction d);//将点乘以方向以获得该方向上下一个点的坐标
	Point* getActualPoint();
};
