#include"Buttons.h"
#include"Button.h"
#include<list>

void add(Button* x) {
	buttons.push_back(x);
}

void clear() {
	buttons.clear();
}

void forbuttons() {
	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();

		for (i = buttons.begin(); i != buttons.end(); ++i) {
			if (i->ifClick(m.x, m.y)) {
				i->role();
				break;
			}
		}

		FlushMouseMsgBuffer();//清空鼠标输入缓冲区
	}
}