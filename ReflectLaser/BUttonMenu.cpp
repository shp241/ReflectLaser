#include <conio.h>
#include <graphics.h>  // ����ͼ�ο�ͷ�ļ�4-444
#include <easyx.h>
//#include "Picture.h"
#include <iostream>
#include <string>
using std::string;

IMAGE* ButtonStart() {   //����200*100�İ�ťͼ����

  IMAGE pImg[4];
  LPCTSTR text[]={"START", "OPTION", "ABOUT", "EXIT"};
  //SetWorkingImage();
  for (int i=0;i<4;i++){
    initgraph(400, 400);
    setfillcolor(RGB(195, 195, 195));
    setlinecolor(RGB(195, 195, 195));
  //setbkcolor(WHITE);
  fillrectangle(0, 0, 200, 100);
  RECT r{0, 0, 200, 100};
  setbkmode(TRANSPARENT);
  settextcolor(BLACK);
  settextstyle(70,0,"΢���ź�");
  drawtext(text[i], &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  getimage(&pImg[i],0,0,200,100);
  cleardevice();
  }

  getchar();
  closegraph();
  return pImg;
}

int main() { 
  IMAGE *a = ButtonStart();
  initgraph(800, 600);
 
  putimage(200, 200, &a[0] );
  getchar();
  closegraph();
}

