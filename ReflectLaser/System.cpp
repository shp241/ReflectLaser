#include "System.h"

list<Button*> System::buttons = {};//��ť����
Level* System::game = new Level();//ָʾ��ǰ���е���Ϸ

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
		FlushMouseMsgBuffer();//���������뻺����
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