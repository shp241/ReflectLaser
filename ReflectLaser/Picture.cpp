#include <graphics.h>
#include "Picture.h"

map<string, IMAGE*> Picture::loaded = {};

Picture::Picture(int w, int h) {
	initgraph(w, h);
}

void Picture::putPicture(string picture, Point a) {
	if (loaded.count(picture) == 0) {
		loadPictrue(picture);
	}
	putimage(a.getX(), a.getY(), loaded[picture]);
}

void Picture::loadPictrue(string name) {
	string filename = "images\\" + name + ".png";
	IMAGE* pImg = new IMAGE();
	loadimage(pImg, filename.c_str());
	loaded.insert(map<string, IMAGE*>::value_type(name, pImg));
}

Picture::~Picture() {
	delete &loaded;
	closegraph();
}