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
};//���˵���ť

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role(Picture* p);
};//��ʼ��Ϸ��ť

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role(Picture* p);
};//ѡ�ť

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role(Picture* p);
};//������ť

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role(Picture* p);
};//�˳���ť