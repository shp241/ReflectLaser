#include"MenuOperate.h"
#include"Button.h"
#include"Chapter.h"
#include"Picture.h"

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
  
  p.putPicture(*(BChapterOne->getP(0)),"ChapterOne");//在按钮处贴图
  p.putPicture(*(BChapterTwo->getP(0)),"ChapterTwo");
  p.putPicture(*(BChapterThree->getP(0)),"ChapterThree");
  p.putPicture(*(BChapterFour->getP(0)),"ChapterFour");
  p.putPicture(*(BChapterFive->getP(0)),"ChapterFive");

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