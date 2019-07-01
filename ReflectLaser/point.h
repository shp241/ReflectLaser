#pragma once
class Point{
private:
  int x, y;
public:
  int getx();
  int gety();
  Point(int x_, int y_);
  Point() = default;
};