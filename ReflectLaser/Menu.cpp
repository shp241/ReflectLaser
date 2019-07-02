#include"Menu.h"
#include<easyx.h>
#include<graphics.h>
#include"Button.h"
#include"MenuOperate.h"
#include"Picture.h"

void menu() {
	Picture p = Picture();
        //����ͼƬ
	p.loadPictrue("Background");
	p.loadPictrue("Start");
	p.loadPictrue("Option");
	p.loadPictrue("Exit");
        p.loadPictrue("ChapterOne");
        p.loadPictrue("ChapterTwo");
        p.loadPictrue("ChapterThree");
        p.loadPictrue("ChapterFour"); 
        p.loadPictrue("ChapterFive");

	p.putPicture(*(new Point(0,0)),"background");//������ҳ��ı���

	Button* BStart = new Button(new Point( , ), new Point( , ));
	Button* BOption = new Button(new Point( , ), new Point( , ));
	Button* BHelp = new Button(new Point( , ), new Point( , ));
	Button* BExit = new Button(new Point( , ), new Point( , ));

	p.putPicture(*(BStart->getP(0)),"Start");//���ư�ť
	p.putPicture(*(BOption->getP(0)),"Option");
	p.putPicture(*(BHelp->getP(0)),"Help");
	p.putPicture(*(BExit->getP(0)),"Exit");
	


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