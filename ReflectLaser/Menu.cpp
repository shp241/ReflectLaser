#include"Menu.h"
#include<easyx.h>
#include<graphics.h>
#include"Button.h"
#include"MenuOperate.h"
#include"Picture.h"

void menu() {
	Picture p = Picture();

	Button* BStart = new Button(new Point(, ), new Point(, ));
	Button* BOption = new Button(new Point(, ), new Point(, ));
	Button* BHelp = new Button(new Point(, ), new Point(, ));
	Button* BExit = new Button(new Point(, ), new Point(, ));

	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (BStart->ifClick(m.x, m.y)) {
			start(p);
		}//�������ʼ��Ϸ
		if (BOption->ifClick(m.x, m.y)) {
			option(p);
		}//ѡ��
		if (BHelp->ifClick(m.x, m.y)) {
			help(p);
		}//����
		if (BExit->ifClick(m.x, m.y)) {
			exit(p);
		}//�˳�
	}
}