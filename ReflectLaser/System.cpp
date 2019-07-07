#include "System.h"

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
	Picture* p = Menu::menu();
	forButtons(p);
}

void System::forButtons(Picture* p) {
	list<Button*>::iterator it;
	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();
		for (it = buttons.begin(); it != buttons.end(); ++it) {
			if ((*it)->ifClick(m.x, m.y)) {
				(*it)->role(p);
				break;
			}
		}
		FlushMouseMsgBuffer();//清空鼠标输入缓冲区
	}
}