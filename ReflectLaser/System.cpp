#include "System.h"

list<Button*> System::buttons = {};//按钮容器
Level* System::game = new Level();//指示当前进行的游戏

void System::add(Button* x) {
	buttons.push_back(x);
}

void System::clear() {
	list<Button*>::iterator it;
	for (it = buttons.begin(); it != buttons.end(); ++it) {
		delete *it;
	}
	buttons.clear();
}

void System::system() {
	MainMenu(new Point(), new Point()).role();
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