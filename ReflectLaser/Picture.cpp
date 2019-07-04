#include <graphics.h>  // 引用图形库头文件4-444
#include "Picture.h"

map<string, IMAGE*> Picture::loaded = {};

Picture::Picture(int w = 800, int h = 600) {
	initgraph(w, h);
}

void Picture::putPicture(Point a, string picture) {
	putimage(a.getX(), a.getY(), loaded[picture]);
}//画图函数

void Picture::loadPictrue(string name) {
	string filename = name + ".png";
	IMAGE* pImg = new IMAGE();
	loadimage(pImg, filename.c_str());
	loaded.insert(map<string, IMAGE*>::value_type(name, pImg));
}//加载图片函数