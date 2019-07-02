#pragma once
#include"RelativePoint.h"
#include"Point.h"

class RelativePoint : public Point {

private:
  int x, y;

public:
  RelativePoint(int x = 0, int y = 0);
  RelativePoint(const RelativePoint& p);
  RelativePoint operator*(Direction d);
};

