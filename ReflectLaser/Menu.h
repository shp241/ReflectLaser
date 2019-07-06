#pragma once
#include"Button.h"
#include"Picture.h"
using std::string;

namespace Menu {
	Picture* menu(Picture* p = new Picture());
	void start(Picture* p);
	void option(Picture* p);
	void help(Picture* p);
	void exit(Picture* p);
}

class MainMenu :public Button {
public:
	MainMenu(Point* p0, Point* p1);
	void role(Picture* p);
};

class Start :public Button {
public:
	void role(Picture* p);
};

class Option :public Button {
public:
	void role(Picture* p);
};

class Help :public Button {
public:
	void role(Picture* p);
};

class Exit :public Button {
public:
	void role(Picture* p);
};