#pragma once
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#include <ctime>
#include <list>
#include <stdio.h>
#include <windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#include "Button.h"
#include "DoubleMirror.h"
#include "Emitter.h"
#include "HalfMirror.h"
#include "Level.h"
#include "Mirror.h"
#include "Picture.h"
#include "Target.h"
#include "Wall.h"
using std::list;
using std::string;

class System {
public:
	static Level* levels[12];//�洢���йؿ�
	static list<Button*> buttons;//��ť����
	static Level* game;//ָʾ��ǰ���е���Ϸ
	static int chapters;//ָʾ��ǰ���еĹؿ�
	static bool musicOn;//ָʾ�������ֿ���
	static void initialize();//��ʼ��
	static void add(Button* x);//����������Ӱ�ť
	static void clear();//������������а�ť
	static void system();//ִ�г���������
	static void forButtons();//����������ť����ѭ��
	static void refresh();//ˢ�¹ؿ����
	static void music(string m);//�����ļ���������
	static void resetLevel();//���ùؿ�
};

class MainMenu :public Button {
public:
	MainMenu(Point* p0, Point* p1);
	void role();
	~MainMenu() = default;
};//���˵���ť

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role();
	~Start() = default;
};//��ʼ��Ϸ��ť

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role();
	~Option() = default;
};//ѡ�ť

class Music :public Button {
private:
	string music;//�ð�ť��ŵ�����
public:
	Music(Point* p0, Point* p1, string music);
	virtual void role();
	~Music() = default;
};//���ְ�ť

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role();
	~Help() = default;
};//������ť

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role();
	~Exit() = default;
};//�˳���ť

class Chapter :public Button {//�ؿ���ť���
private:
	int chapters;//�ؿ����
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role();
	~Chapter() = default;
};

class Rotate :public Button {//��ת��ť���
private:
	bool clocked;//�Ƿ���˳ʱ��
public:
	Rotate(Point* p0, Point* p1, bool clocked);
	void role();
	~Rotate() = default;
};

class Close :public Button {
public:
	Close(Point* p0, Point* p1);
	void role();
	~Close() = default;
};

class BlockButton :public Button {
private:
	Block* block;
public:
	BlockButton(Point* p0, Point* p1, Block* block);
	BlockButton(Block* block = new Block(new RelativePoint(-1, 0)));
	void role();
	~BlockButton() = default;
};