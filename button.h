#pragma once
#include"point.h"
#include<graphics.h>

class Button {
private:
  Point a, b;//按钮矩形区域的两个对角顶点（顺时针）
public:
  Button(Point* a_, Point* b);

  bool if_click(int x__,int y__ );

};