#include "Picture.h"

map<string, IMAGE*> Picture::loaded = {};
bool Picture::opening = false;

void Picture::open(int w, int h) {
	initgraph(w, h);
	opening = true;
}

void Picture::putPicture(string picture, Point a) {
	if (loaded.count(picture) == 0) {
		loadPictrue(picture);
	}
	putimage(a.getX(), a.getY(), loaded[picture]);
}

void Picture::loadPictrue(string name) {
	string filename = "Images\\" + name + ".png";
	IMAGE* pImg = new IMAGE();
	loadimage(pImg, filename.c_str());
	loaded.insert(map<string, IMAGE*>::value_type(name, pImg));
}

void Picture::close() {
	closegraph();
	opening = false;
}