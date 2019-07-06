#include "Menu.h"
#include "System.h"

std::list<Button*> buttons;//��ť����
std::list<Button*>::iterator i;

void add(Button* x) {
	buttons.push_back(x);
}

void clear() {
	buttons.clear();
}

void system() {
	Menu* menuFirst = new Menu();
	menuFirst->role();
	forButtons();
}

void forButtons() {
	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();
		for (i = buttons.begin(); i != buttons.end(); ++i) {
			if ((*i)->ifClick(m.x, m.y)) {
				(*i)->role();
				break;
			}
		}
		FlushMouseMsgBuffer();//���������뻺����
	}
}