#pragma once
#include <easyx.h>
#include <map>
#include <string>
#include "Point.h"
using std::map;
using std::string;

class Picture {//���ڼ���ͼƬ�ͷ���ͼƬ
private:
	static map<string, IMAGE*> loaded;//���ڴ���Ѽ��ص�ͼƬ
public:
	Picture(int w = 800, int h = 600);
	void putPicture(string picture, Point p = Point(0, 0));//��pλ�÷�������Ϊpicture��ͼƬ����δ��������м���
	void loadPictrue(string filename);//��������Ϊpicture��ͼƬ
	~Picture();
};