#pragma once
#include"RelativePoint.h"
#include"Point.h"

class RelativePoint : public Point {

public:
  RelativePoint(int x = 0, int y = 0);
  RelativePoint operator*(Direction d);
};

