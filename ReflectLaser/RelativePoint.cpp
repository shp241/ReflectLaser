#include"RelativePoint.h"
RelativePoint RelativePoint::operator*(Direction d) {
  return RelativePoint(this->getX() + d.getX(), this->getY() + d.getY());
}

RelativePoint::RelativePoint(int x, int y) {
  setX(x);
  setY(y);
}
