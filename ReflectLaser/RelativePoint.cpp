#include"RelativePoint.h"
RelativePoint RelativePoint::operator*(Direction d) {
  return RelativePoint(this->x += d.getX(), this->y += d.getY());
}

RelativePoint::RelativePoint(int x, int y) {
  this->x = x;
  this->y = y;
}

RelativePoint::RelativePoint(const RelativePoint& p) {
  this->x = p.x;
  this->y = p.y;
}