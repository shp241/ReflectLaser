#pragma once
#include "Button.h"
#include "Picture.h"
#include "System.h"
using std::string;

class MainMenu :public Button {
public:
	MainMenu(Point* p0, Point* p1);
	void role();
};//���˵���ť

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role();
};//��ʼ��Ϸ��ť

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role();
};//ѡ�ť

class Music :public Button {
public:
  Music(Point* p0, Point* p1);
  void role();
};//���ְ�ť

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role();
};//������ť

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role();
};//�˳���ť

class Chapter :public Button {//�ؿ���ť���
private:
	int chapters;//�ؿ����
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role();
};

class Rotate :public Button {//��ת��ť���
private:
	bool clocked;//�Ƿ���˳ʱ��
public:
	Rotate(Point* p0, Point* p1, bool clocked);
	void role();
};