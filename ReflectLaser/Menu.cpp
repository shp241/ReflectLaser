#include"Menu.h"
#include<easyx.h>
#include<graphics.h>
#include"Button.h"
#include"MenuOperate.h"
#include"Picture.h"
#include"Chapter.h"

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

void start(Picture p) {
  chooseChapter(p);


}

void option(Picture p) {
  Button* Bmusic = new Button(new Point(, ), new Point(, ));//选项一：音乐开关

  MOUSEMSG m;
  m = GetMouseMsg();

  if (Bmusic->ifClick(m.x, m.y)) {

  }

}

void help(Picture p) {


}

void exit(Picture p) {


}

void chooseChapter(Picture p) {

  p.putPicture(*(new Point(0, 0)), "background");//绘制关卡选择界面的背景

  Button* BChapterOne = new Button(new Point(, ), new Point(, ));
  Button* BChapterTwo = new Button(new Point(, ), new Point(, ));
  Button* BChapterThree = new Button(new Point(, ), new Point(, ));
  Button* BChapterFour = new Button(new Point(, ), new Point(, ));
  Button* BChapterFive = new Button(new Point(, ), new Point(, ));

  p.putPicture(*(BChapterOne->getP(0)), "ChapterOne");//在按钮处贴图
  p.putPicture(*(BChapterTwo->getP(0)), "ChapterTwo");
  p.putPicture(*(BChapterThree->getP(0)), "ChapterThree");
  p.putPicture(*(BChapterFour->getP(0)), "ChapterFour");
  p.putPicture(*(BChapterFive->getP(0)), "ChapterFive");

  FlushMouseMsgBuffer();//清空鼠标输入缓冲区
  MOUSEMSG m;
  m = GetMouseMsg();//获取鼠标输入信息

  if (BChapterOne->ifClick(m.x, m.y)) {
    chapterOne(p);
  }//第一关

  if (BChapterTwo->ifClick(m.x, m.y)) {
    chapterTwo(p);
  }//第二关

  if (BChapterThree->ifClick(m.x, m.y)) {
    chapterThree(p);
  }//第三关

  if (BChapterFour->ifClick(m.x, m.y)) {
    chapterFour(p);
  }//第四关

  if (BChapterFive->ifClick(m.x, m.y)) {
    chapterFive(p);
  }//第五关
}