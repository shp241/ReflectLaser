#include"MenuOperate.h"
#include"Button.h"
#include"Chapter.h"

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
  Button* BChapterOne = new Button(new Point(, ), new Point(, ));
  Button* BChapterTwo = new Button(new Point(, ), new Point(, ));
  Button* BChapterThree = new Button(new Point(, ), new Point(, ));
  Button* BChapterFour = new Button(new Point(, ), new Point(, ));
  Button* BChapterFive = new Button(new Point(, ), new Point(, ));

  MOUSEMSG m;
  m = GetMouseMsg();

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