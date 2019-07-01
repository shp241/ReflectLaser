#include"button.h"
#include<graphics.h>

Button::Button(Point* a_, Point* b_) {
  a = *a_;
  b = *b_;
}


bool Button::if_click(int x_, int y_) {
  if ( x_< && x> && y< && y>) {
    return true;
  }
  if (!(x_< && x> && y< && y>)) {
    return false;
  }
}