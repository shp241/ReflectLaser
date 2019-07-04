#pragma once
#include <easyx.h>
#include "Point.h"
#include <string>
#include <map>
using std::string;
using std::map;

class Picture {
private:
	static map<string, IMAGE*> loaded;
public:
	Picture(int w = 800, int h = 600);
	void putPicture(Point a, string picture);
	void loadPictrue(string filename);
	~Picture();
};