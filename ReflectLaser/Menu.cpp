#include "Menu.h"

//MainMenu类
MainMenu::MainMenu(Point* p0, Point* p1) :Button(p0, p1) {}

void MainMenu::role(Picture* p) {
	Menu::menu(p);
}

//Start类
Start::Start(Point* p0, Point* p1) :Button(p0, p1) {}

void Start::role(Picture* p) {
	Menu::start(p);
}

//Option类
Option::Option(Point* p0, Point* p1) :Button(p0, p1) {}

void Option::role(Picture* p) {
	Menu::option(p);
}

//Help类
Help::Help(Point* p0, Point* p1) : Button(p0, p1) {}

void Help::role(Picture* p) {
	Menu::help(p);
}

//Exit类
Exit::Exit(Point* p0, Point* p1) :Button(p0, p1) {}

void Exit::role(Picture* p) {
	Menu::exit(p);
}

//menu命名空间中的函数
Picture* Menu::menu(Picture* p) {
	System::clear();
	p->putPicture("Menu\\MainWindow");//绘制主页面的背景
	Button* BStart = new Start(new Point(400, 180), new Point(400 + 250, 180 + 80));//实例化四个主菜单按钮
	Button* BOption = new Option(new Point(400, 280), new Point(400 + 250, 280 + 80));
	Button* BHelp = new Help(new Point(400, 380), new Point(400 + 250, 380 + 80));
	Button* BExit = new Exit(new Point(400, 480), new Point(400 + 250, 480 + 80));
	System::add(BStart);//将上述四个按钮放入buttons容器中
	System::add(BOption);
	System::add(BHelp);
	System::add(BExit);
	return p;
}

void Menu::start(Picture* p) {
	System::clear();//进入该函数后，将容器中已有的按钮删除
	p->putPicture("Menu\\ChapterChoose");//绘制关卡选择界面的背景
	Button* BChapter[12];//实例化五个关卡选择按钮
	int ChapterY[3] = { 160,290,430 };
	int ChapterX[4] = { 40 ,230,420, 620 };
	int width = 140;
	int height = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			BChapter[i * 4 + j] = new Chapter(new Point(ChapterX[j], ChapterY[i]),
				new Point(ChapterX[j] + width, ChapterY[i] + height), i * 4 + j);
		}
	}
	for (int i = 0; i < 12; i++) {
		System::add(BChapter[i]);
	}//将12个关卡选择按钮放入容器
}

void Menu::option(Picture* p) {
	System::clear();
	Button* Bmusic = new Button(new Point(, ), new Point(, ));//选项一：音乐开关
	if (Bmusic->ifClick(m.x, m.y)) {
		//设置音乐开关的函数
	}
}

void Menu::help(Picture* p) {
	System::clear();
}

void Menu::exit(Picture* p) {
	System::clear();
	delete &p;
}