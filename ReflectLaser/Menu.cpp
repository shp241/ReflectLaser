#include "Menu.h"

//MainMenu类
MainMenu::MainMenu(Point* p0, Point* p1) :Button(p0, p1) {}

void MainMenu::role() {
	System::clear();
	System::game->clear();
	Picture::putPicture("Menu\\MainWindow");//绘制主页面的背景
	Button* BStart = new Start(new Point(400, 180), new Point(400 + 250, 180 + 80));//实例化四个主菜单按钮
	Button* BOption = new Option(new Point(400, 280), new Point(400 + 250, 280 + 80));
	Button* BHelp = new Help(new Point(400, 380), new Point(400 + 250, 380 + 80));
	Button* BExit = new Exit(new Point(400, 480), new Point(400 + 250, 480 + 80));
	System::add(BStart);//将上述四个按钮放入buttons容器中
	System::add(BOption);
	System::add(BHelp);
	System::add(BExit);
}

//Start类
Start::Start(Point* p0, Point* p1) :Button(p0, p1) {}

void Start::role() {
	System::clear();//进入该函数后，将容器中已有的按钮删除
	Picture::putPicture("Menu\\ChapterChoose");//绘制“关卡选择”界面
	Button* BChapter[12];//实例化十二个关卡选择按钮
	Button* BMenu = new MainMenu(new Point(0, 0), new Point(150, 100));
	System::add(BMenu);
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

//Option类
Option::Option(Point* p0, Point* p1) :Button(p0, p1) {}

void Option::role() {
	System::clear();
	Picture::putPicture("Menu\\Option");//绘制“选项”界面
	Button* BMusic = new Music(new Point(450, 100), new Point(450 + 250, 100 + 80), System::musicOn ? "Music\\MenuMusic.wav" : "");
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));
	System::add(BMenu);
	System::add(BMusic);
}

//Music类
Music::Music(Point* p0, Point* p1, string music) :Button(p0, p1) {
	this->music = music;
}

void Music::role() {
	System::clear();//清空容器
	System::musicOn = !System::musicOn;
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//实例化一个主菜单按钮
	Button* BMusic;
	if (music == "") {
		BMusic = new Music(new Point(450, 100), new Point(450 + 250, 100 + 80), "Music\\MenuMusic.wav");//在刚刚的音乐按钮位置实例化一个音乐按钮
	}
	else {
		BMusic = new Music(new Point(450, 100), new Point(450 + 250, 100 + 80), "");//在刚刚的音乐按钮位置实例化一个音乐按钮
	}
	System::add(BMenu);//放入容器
	System::add(BMusic);
	System::music(music);
}

//Help类
Help::Help(Point* p0, Point* p1) : Button(p0, p1) {}

void Help::role() {
	System::clear();//进入该函数后，将容器中已有的按钮删除
	Picture::putPicture("Menu\\Help");//绘制关卡选择界面的背景
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//实例化主菜单按钮
	System::add(BMenu);
}

//Exit类
Exit::Exit(Point* p0, Point* p1) :Button(p0, p1) {}

void Exit::role() {
	System::clear();//清空容器
	Picture::close();//关闭窗口
}

//Chapter类
Chapter::Chapter(Point* p0, Point* p1, int chapters) :Button(p0, p1) {
	this->chapters = chapters;
}

void Chapter::role() {
	System::clear();//进入该函数后，将容器中已有的按钮删除
	Picture::putPicture("Menu\\PlayingWindow");//绘制“游戏”界面
	if (System::musicOn) {
		System::music("Music\\PlayingMusic.wav");
	}
	System::game = new Level("Level_" + to_string(chapters));
	Button* BNext = new Chapter(new Point(640, 400), new Point(640 + 120, 400 + 40), (chapters + 1) % 12);
	Button* BBack = new Start(new Point(640, 460), new Point(640 + 120, 460 + 40));
	Button* BAntiClocked = new Rotate(new Point(640, 320), new Point(640 + 40, 320 + 40), false);
	Button* BClocked = new Rotate(new Point(720, 320), new Point(720 + 40, 320 + 40), false);
	RelativePoint* p = new RelativePoint();
	for (int i = 0; i < 15; i++) {
		p->setX(i);
		for (int j = 0; j < 15; j++) {
			p->setY(j);
			System::add((*System::game->getMap())[*p]);
		}
	}//将225个方块按钮放入容器
	for (int i = 0; i < 24; i++) {
		System::add(System::game->getItem(i));
	}//将24个道具按钮放入容器
	System::add(BAntiClocked);
	System::add(BClocked);
	System::add(BNext);
	System::add(BBack);
	System::refresh();
}

//Rotate类
Rotate::Rotate(Point* p0, Point* p1, bool clocked) :Button(p0, p1) {
	this->clocked = clocked;
}

void Rotate::role() {
	System::game->getCache()->rotate(clocked);
	System::refresh();
}

//Close类
Close::Close(Point* p0, Point* p1) :Button(p0, p1) {}

void Close::role() {
	System::rid(*this);
	Picture::putPicture("Menu\\PlayingWindow");
	System::game->draw();
}