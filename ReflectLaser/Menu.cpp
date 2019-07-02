#include"Menu.h"
#include<easyx.h>
#include<graphics.h>
#include"Button.h"
#include"MenuOperate.h"
#include"Picture.h"

void menu() {
	Picture p = Picture();
        //加载图片
	p.loadPictrue("Background");
	p.loadPictrue("Start");
	p.loadPictrue("Option");
	p.loadPictrue("Exit");
        p.loadPictrue("ChapterOne");
        p.loadPictrue("ChapterTwo");
        p.loadPictrue("ChapterThree");
        p.loadPictrue("ChapterFour"); 
        p.loadPictrue("ChapterFive");

	p.putPicture(*(new Point(0,0)),"background");//绘制主页面的背景

	Button* BStart = new Button(new Point( , ), new Point( , ));
	Button* BOption = new Button(new Point( , ), new Point( , ));
	Button* BHelp = new Button(new Point( , ), new Point( , ));
	Button* BExit = new Button(new Point( , ), new Point( , ));

	p.putPicture(*(BStart->getP(0)),"Start");//绘制按钮
	p.putPicture(*(BOption->getP(0)),"Option");
	p.putPicture(*(BHelp->getP(0)),"Help");
	p.putPicture(*(BExit->getP(0)),"Exit");
	


	for (;;) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (BStart->ifClick(m.x, m.y)) {
			start(p);
		}//鼠标点击开始游戏
		if (BOption->ifClick(m.x, m.y)) {
			option(p);
		}//选项
		if (BHelp->ifClick(m.x, m.y)) {
			help(p);
		}//帮助
		if (BExit->ifClick(m.x, m.y)) {
			exit(p);
		}//退出
	}
}