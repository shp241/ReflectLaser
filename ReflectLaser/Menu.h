#pragma once
#include "Button.h"
#include "Picture.h"
#include "System.h"
using std::string;

class MainMenu :public Button {
public:
	MainMenu(Point* p0, Point* p1);
	void role();
};//主菜单按钮

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role();
};//开始游戏按钮

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role();
};//选项按钮

class Music :public Button {
public:
  Music(Point* p0, Point* p1);
  void role();
};//音乐按钮

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role();
};//帮助按钮

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role();
};//退出按钮

class Chapter :public Button {//关卡按钮点击
private:
	int chapters;//关卡编号
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role();
};

class Rotate :public Button {//旋转按钮点击
private:
	bool clocked;//是否是顺时针
public:
	Rotate(Point* p0, Point* p1, bool clocked);
	void role();
};