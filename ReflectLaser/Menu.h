#pragma once
#include "Button.h"
#include "Chapter.h"
#include "Picture.h"
#include "System.h"
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
};//主菜单按钮

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role(Picture* p);
};//开始游戏按钮

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role(Picture* p);
};//选项按钮

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role(Picture* p);
};//帮助按钮

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role(Picture* p);
};//退出按钮