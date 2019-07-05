#include"Button.h"
#include "Menu.h"
#include<easyx.h>
#include<graphics.h>
#include "Picture.h"
#include<iostream>
#include"System.h"

using std::string;

void Menu::role() {
  menu();
}

void Start::role(Picture p) {
  start(p);
}

void Option::role(Picture p) {
  option(p);
}

void Help::role(Picture p) {
  help(p);
}

void Exit::role(Picture p) {
  exit(p);
}

void menu() {
  Picture p = Picture();

  //加载图片
  p.loadPictrue("Background");
  p.loadPictrue("Start");
  p.loadPictrue("Option");
  p.loadPictrue("Help");
  p.loadPictrue("Exit");
  p.loadPictrue("ChapterOne");
  p.loadPictrue("ChapterTwo");
  p.loadPictrue("ChapterThree");
  p.loadPictrue("ChapterFour");
  p.loadPictrue("ChapterFive");


  Button* BStart = new Button(new Point(, ), new Point(, ));//实例化四个主菜单按钮
  Button* BOption = new Button(new Point(, ), new Point(, ));
  Button* BHelp = new Button(new Point(, ), new Point(, ));
  Button* BExit = new Button(new Point(, ), new Point(, ));

  add(BStart);//将上述四个按钮放入buttons容器中
  add(BOption);
  add(BHelp);
  add(BExit);

  p.putPicture(*(new Point(0, 0)), "background");//绘制主页面的背景
  p.putPicture(*(BStart->getP(0)), "Start");//绘制按钮
  p.putPicture(*(BOption->getP(0)), "Option");
  p.putPicture(*(BHelp->getP(0)), "Help");
  p.putPicture(*(BExit->getP(0)), "Exit");
}

void start(Picture p) {
  chooseChapter(p);
}

void option(Picture p) {
  Button* Bmusic = new Button(new Point(, ), new Point(, ));//选项一：音乐开关

  MOUSEMSG m;
  m = GetMouseMsg();

  if (Bmusic->ifClick(m.x, m.y)) {
    //设置音乐开关的函数
  }
}

void help(Picture p) {
}

void exit(Picture p) {
  closegraph();
}

void chooseChapter(Picture p) {
  p.putPicture(*(new Point(0, 0)), "background");//绘制关卡选择界面的背景

  Button* BChapterOne = new Button(new Point(, ), new Point(, ));//实例化五个关卡选择按钮
  Button* BChapterTwo = new Button(new Point(, ), new Point(, ));
  Button* BChapterThree = new Button(new Point(, ), new Point(, ));
  Button* BChapterFour = new Button(new Point(, ), new Point(, ));
  Button* BChapterFive = new Button(new Point(, ), new Point(, ));

  p.putPicture(*(BChapterOne->getP(0)), "ChapterOne");//在按钮处贴图
  p.putPicture(*(BChapterTwo->getP(0)), "ChapterTwo");
  p.putPicture(*(BChapterThree->getP(0)), "ChapterThree");
  p.putPicture(*(BChapterFour->getP(0)), "ChapterFour");
  p.putPicture(*(BChapterFive->getP(0)), "ChapterFive");

  clear();//进入该函数后，将容器中已有的四个按钮（开始、选择、帮助、退出）删除
  add(BChapterOne);//将五个关卡选择按钮放入容器
  add(BChapterTwo);
  add(BChapterThree);
  add(BChapterFour);
  add(BChapterFive);
}







