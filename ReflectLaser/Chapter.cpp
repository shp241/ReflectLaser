#include "Chapter.h"

Chapter::Chapter(Point* p0, Point* p1, int chapters) :Button(p0, p1) {
	this->chapters = chapters;
}

void Chapter::role(Picture* p) {
	System::clear();//����ú����󣬽����������еİ�ťɾ��
	p->putPicture("Menu\\ChapterChoose");//���ƹؿ�ѡ�����ı���
	Button* BChapter[12];//ʵ��������ؿ�ѡ��ť
	int ChapterY[3] = { 160,290,430 };
	int ChapterX[4] = { 40 ,230,420, 620 };
	int width = 140;
	int height = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			BChapter[i * 4 + j] = new Chapter(new Point(ChapterX[j], ChapterY[i]),
				new Point(ChapterX[j] + width, ChapterY[i] + height), i * 4 + j);
		}
	}
	for (int i = 0; i < 12; i++) {
		System::add(BChapter[i]);
	}//��12���ؿ�ѡ��ť��������
}