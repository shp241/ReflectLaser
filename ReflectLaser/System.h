#pragma once
#include <list>
#include "Button.h"
#include "Level.h"
#include "Menu.h"
using std::list;

namespace System {
	list<Button*> buttons = {};//��ť����
	Level* game = new Level();//ָʾ��ǰ���е���Ϸ
	void add(Button* x);//����������Ӱ�ť
	void clear();//������������а�ť
	void system();//ִ�г���������
	void forButtons(Picture* p);//����������ť����ѭ��
}