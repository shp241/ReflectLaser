#include "System.h"

list<Button*> System::buttons = {};//按钮容器
Level* System::game = new Level();//指示当前进行的游戏
bool System::musicOn = true;

void System::initialize() {
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
	System::music("Music\\MenuMusic.wav");
}

void System::add(Button* x) {
	buttons.push_back(x);
}

void System::rid(Button x) {
	list<Button*>::iterator it;
	for (it = buttons.begin(); it != buttons.end(); ++it) {
		if (typeid(**it) == typeid(x)) {
			buttons.erase(it);
		}
	}
}

void System::clear() {
	list<Button*>::iterator it;
	for (it = buttons.begin(); it != buttons.end(); ++it) {
		delete *it;
	}
	buttons.clear();
}

void System::system() {
	initialize();
	forButtons();
}

void System::forButtons() {
	list<Button*>::iterator it;
	while (Picture::opening) {
		MOUSEMSG m;
		m = GetMouseMsg();
		for (it = buttons.begin(); it != buttons.end(); ++it) {
			if ((*it)->ifClick(m.x, m.y)) {
				(*it)->role();
				break;
			}
		}
		FlushMouseMsgBuffer();//清空鼠标输入缓冲区
	}
}

void System::refresh() {
	Picture::putPicture("Menu\\PlayingWindow");
	game->draw();
	if (game->isWin()) {
		Picture::putPicture("Menu\\SuccessNotice", Point(250, 200));
		Button* BClose = new Close(new Point(489, 368), new Point(489 + 54, 368 + 25));
		add(BClose);
	}
}

void System::music(string m) {
	PlaySound(m == "" ? nullptr : m.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}