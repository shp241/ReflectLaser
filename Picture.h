#pragma once
#include <easyx.h>
#include <iostream>

class Picture {
 private:
  IMAGE *address;  //ͼƬָ��
  Point a;  
 public:
    
  Picture(int w=800,int h=600) { 
    initgraph(w,h);
  }
  Picture(int w = 800, int h = 600) { initgraph(w, h); }
  Picture(Point a, IMAGE *address) {//����ͼ�� ��ָ�����
    loadimage(a.getX, );
    putimage(a.getX, a.getY, address);
  }
  Picture
};