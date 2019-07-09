#pragma once
#include <easyx.h>
#include <map>
#include <string>
#include "Point.h"
#include "Vector.h"
using std::map;
using std::string;

class Picture {//���ڼ���ͼƬ�ͷ���ͼƬ
private:
	static map<string, IMAGE*> loaded;//���ڴ���Ѽ��ص�ͼƬ
public:
	static bool opening;//��־�Ƿ��Ѽ��ش���
	static void open(int w = 800, int h = 600);//�򿪴���
	static void putPicture(string picture, Point p = Point(0, 0));//��pλ�÷�������Ϊpicture��ͼƬ����δ��������м���
	static void loadPictrue(string filename);//��������Ϊpicture��ͼƬ
	static void drawVector(Vector* v);//������
	static void close();//�رմ���
};