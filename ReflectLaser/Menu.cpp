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

  //����ͼƬ
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


  Button* BStart = new Button(new Point(, ), new Point(, ));//ʵ�����ĸ����˵���ť
  Button* BOption = new Button(new Point(, ), new Point(, ));
  Button* BHelp = new Button(new Point(, ), new Point(, ));
  Button* BExit = new Button(new Point(, ), new Point(, ));

  add(BStart);//�������ĸ���ť����buttons������
  add(BOption);
  add(BHelp);
  add(BExit);

  p.putPicture(*(new Point(0, 0)), "background");//������ҳ��ı���
  p.putPicture(*(BStart->getP(0)), "Start");//���ư�ť
  p.putPicture(*(BOption->getP(0)), "Option");
  p.putPicture(*(BHelp->getP(0)), "Help");
  p.putPicture(*(BExit->getP(0)), "Exit");
}

void start(Picture p) {
  chooseChapter(p);
}

void option(Picture p) {
  Button* Bmusic = new Button(new Point(, ), new Point(, ));//ѡ��һ�����ֿ���

  MOUSEMSG m;
  m = GetMouseMsg();

  if (Bmusic->ifClick(m.x, m.y)) {
    //�������ֿ��صĺ���
  }
}

void help(Picture p) {
}

void exit(Picture p) {
  closegraph();
}

void chooseChapter(Picture p) {
  p.putPicture(*(new Point(0, 0)), "background");//���ƹؿ�ѡ�����ı���

  Button* BChapterOne = new Button(new Point(, ), new Point(, ));//ʵ��������ؿ�ѡ��ť
  Button* BChapterTwo = new Button(new Point(, ), new Point(, ));
  Button* BChapterThree = new Button(new Point(, ), new Point(, ));
  Button* BChapterFour = new Button(new Point(, ), new Point(, ));
  Button* BChapterFive = new Button(new Point(, ), new Point(, ));

  p.putPicture(*(BChapterOne->getP(0)), "ChapterOne");//�ڰ�ť����ͼ
  p.putPicture(*(BChapterTwo->getP(0)), "ChapterTwo");
  p.putPicture(*(BChapterThree->getP(0)), "ChapterThree");
  p.putPicture(*(BChapterFour->getP(0)), "ChapterFour");
  p.putPicture(*(BChapterFive->getP(0)), "ChapterFive");

  clear();//����ú����󣬽����������е��ĸ���ť����ʼ��ѡ�񡢰������˳���ɾ��
  add(BChapterOne);//������ؿ�ѡ��ť��������
  add(BChapterTwo);
  add(BChapterThree);
  add(BChapterFour);
  add(BChapterFive);
}







