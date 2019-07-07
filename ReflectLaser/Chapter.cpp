#include "Chapter.h"

Chapter::Chapter(Point* p0, Point* p1, int chapters) :Button(p0, p1) {
	this->chapters = chapters;
}

void Chapter::role(Picture* p) {
	System::clear();//进入该函数后，将容器中已有的按钮删除
	p->putPicture("Menu\\ChapterChoose");//绘制关卡选择界面的背景
	Button* BChapter[12];//实例化五个关卡选择按钮
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
	}//将12个关卡选择按钮放入容器
}