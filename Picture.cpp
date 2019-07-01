#include <conio.h>
#include <graphics.h>  // 引用图形库头文件4-444
#include <easyx.h>
#include "Picture.h"


 Picture::Picture(int w = 800, int h = 600) { initgraph(w, h); }
Picture::Picture(Point a, IMAGE *pImg) {
 putimage(a.getX, a.getY, pImg);
}
void Picture ::LoadPictrue(IMAGE *pImg, LPCTSTR filename) {
  loadimage(pImg, filename);
  this->pImg = pImg;
}
void Picture::SetIMAGE(IMAGE *pImg) { this->pImg = pImg; }
IMAGE *Picture::GetIMAGE() { return pImg; };
void Picture::ReSize(IMAGE *pImg, int width, int height) {
  Resize(pImg, width, height);
}
void Picture::GetImage(IMAGE *pImg, Point a, int Width, int Height) {
  getimage(pImg, a.getX(), a.getY(), Width, Height);
}