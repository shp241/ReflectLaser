#pragma once
#include"point.h"
#include<graphics.h>

class Button {
private:
  Point a, b;//��ť��������������ԽǶ��㣨˳ʱ�룩
public:
  Button(Point* a_, Point* b);

  bool if_click(int x__,int y__ );

};