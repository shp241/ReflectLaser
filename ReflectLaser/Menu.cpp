#include"Menu.h"
#include<easyx.h>
#include<graphics.h>
#include"Button.h"
#include"MenuOperate.h"

void menu() {
	Picture p1;

	p1.initgraph();

	Button* BStart = new Button(new Point(, ), new Point(, ));
	Button* BOption = new Button(new Point(, ), new Point(, ));
	Button* BHelp = new Button(new Point(, ), new Point(, ));
	Button* BExit = new Button(new Point(, ), new Point(, ));

	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (BStart->if_click(m.x, m.y)) {
			start();
		}//�������ʼ��Ϸ
		if (BOption->if_click(m.x, m.y)) {
			option();
		}//ѡ��
		if (BHelp->if_click(m.x, m.y)) {
			help();
		}//����
		if (BExit->if_click(m.x, m.y)) {
			exit();
		}//�˳�
	}
}