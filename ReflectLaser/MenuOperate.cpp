#include"MenuOperate.h"
#include"Button.h"
#include"Chapter.h"
#include"Picture.h"

void start(Picture p) {
  chooseChapter(p);


}

void option(Picture p) {
  Button* Bmusic = new Button(new Point(, ), new Point(, ));//ѡ��һ�����ֿ���
  
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

  p.putPicture(*(new Point(0, 0)), "background");//���ƹؿ�ѡ�����ı���

  Button* BChapterOne = new Button(new Point(, ), new Point(, ));
  Button* BChapterTwo = new Button(new Point(, ), new Point(, ));
  Button* BChapterThree = new Button(new Point(, ), new Point(, ));
  Button* BChapterFour = new Button(new Point(, ), new Point(, ));
  Button* BChapterFive = new Button(new Point(, ), new Point(, ));
  
  p.putPicture(*(BChapterOne->getP(0)),"ChapterOne");//�ڰ�ť����ͼ
  p.putPicture(*(BChapterTwo->getP(0)),"ChapterTwo");
  p.putPicture(*(BChapterThree->getP(0)),"ChapterThree");
  p.putPicture(*(BChapterFour->getP(0)),"ChapterFour");
  p.putPicture(*(BChapterFive->getP(0)),"ChapterFive");

  FlushMouseMsgBuffer();//���������뻺����
  MOUSEMSG m;
  m = GetMouseMsg();//��ȡ���������Ϣ

  if (BChapterOne->ifClick(m.x, m.y)) {
    chapterOne(p);
  }//��һ��

  if (BChapterTwo->ifClick(m.x, m.y)) {
    chapterTwo(p);
  }//�ڶ���

  if (BChapterThree->ifClick(m.x, m.y)) {
    chapterThree(p);
  }//������

  if (BChapterFour->ifClick(m.x, m.y)) {
    chapterFour(p);
  }//���Ĺ�
  
  if (BChapterFive->ifClick(m.x, m.y)) {
    chapterFive(p);
  }//�����
}