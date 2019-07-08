#pragma once
#include <list>
#include "Button.h"
#include "Level.h"
#include "Menu.h"
using std::list;

class System {
public:
	static list<Button*> buttons;//��ť����
	static Level* game;//ָʾ��ǰ���е���Ϸ
	static void add(Button* x);//����������Ӱ�ť
	static void rid(Button x);//��������ȥ��!ĳһ���͵�ȫ����ť!
	static void clear();//������������а�ť
	static void system();//ִ�г���������
	static void forButtons();//����������ť����ѭ��
	static void refresh();//ˢ�¹ؿ����
};