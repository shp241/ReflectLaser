#pragma once
#include <easyx.h>
#include <iostream>

class Picture {
 private:
  IMAGE *address;  //图片指针
  Point a;  
 public:
    
  Picture(int w=800,int h=600) { 
    initgraph(w,h);
  }
  Picture(int w = 800, int h = 600) { initgraph(w, h); }
  Picture(Point a, IMAGE *address) {//绘制图形 不指定宽高
    loadimage(a.getX, );
    putimage(a.getX, a.getY, address);
  }
  Picture
};