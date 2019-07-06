#include "Menu.h"

//MainMenu��
MainMenu::MainMenu(Point* p0, Point* p1) :Button(p0, p1) {}

void MainMenu::role(Picture* p) {
	Menu::menu(p);
}

//Start��
Start::Start(Point* p0, Point* p1) :Button(p0, p1) {}

void Start::role(Picture* p) {
	Menu::start(p);
}

//Option��
Option::Option(Point* p0, Point* p1) :Button(p0, p1) {}

void Option::role(Picture* p) {
	Menu::option(p);
}

//Help��
Help::Help(Point* p0, Point* p1) : Button(p0, p1) {}

void Help::role(Picture* p) {
	Menu::help(p);
}

//Exit��
Exit::Exit(Point* p0, Point* p1) :Button(p0, p1) {}

void Exit::role(Picture* p) {
	Menu::exit(p);
}

//menu�����ռ��еĺ���
Picture* Menu::menu(Picture* p) {
	System::clear();
	p->putPicture("Menu\\MainWindow");//������ҳ��ı���
	Button* BStart = new Start(new Point(400, 180), new Point(400 + 250, 180 + 80));//ʵ�����ĸ����˵���ť
	Button* BOption = new Option(new Point(400, 280), new Point(400 + 250, 280 + 80));
	Button* BHelp = new Help(new Point(400, 380), new Point(400 + 250, 380 + 80));
	Button* BExit = new Exit(new Point(400, 480), new Point(400 + 250, 480 + 80));
	System::add(BStart);//�������ĸ���ť����buttons������
	System::add(BOption);
	System::add(BHelp);
	System::add(BExit);
	return p;
}

void Menu::start(Picture* p) {
	System::clear();//����ú����󣬽����������еİ�ťɾ��
	p->putPicture("Menu\\ChapterChoose");//���ƹؿ�ѡ�����ı���
	Button* BChapter[12];//ʵ��������ؿ�ѡ��ť
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
	}//��12���ؿ�ѡ��ť��������
}

void Menu::option(Picture* p) {
	System::clear();
	Button* Bmusic = new Button(new Point(, ), new Point(, ));//ѡ��һ�����ֿ���
	if (Bmusic->ifClick(m.x, m.y)) {
		//�������ֿ��صĺ���
	}
}

void Menu::help(Picture* p) {
	System::clear();
}

void Menu::exit(Picture* p) {
	System::clear();
	delete &p;
}