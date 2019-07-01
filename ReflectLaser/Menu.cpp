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
		}//鼠标点击开始游戏
		if (BOption->if_click(m.x, m.y)) {
			option();
		}//选项
		if (BHelp->if_click(m.x, m.y)) {
			help();
		}//帮助
		if (BExit->if_click(m.x, m.y)) {
			exit();
		}//退出
	}
}