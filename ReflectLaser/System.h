#pragma once
#include <list>
#include "Button.h"
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#include <stdio.h>
#include <windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#include "Level.h"
#include "Menu.h"
using std::list;

class System {
public:
	static list<Button*> buttons;//��ť����
	static Level* game;//ָʾ��ǰ���е���Ϸ
	static bool musicOn;//ָʾ�������ֿ���
	static void initialize();//��ʼ��
	static void add(Button* x);//����������Ӱ�ť
	static void rid(Button x);//��������ȥ��!ĳһ���͵�ȫ����ť!
	static void clear();//������������а�ť
	static void system();//ִ�г���������
	static void forButtons();//����������ť����ѭ��
	static void refresh();//ˢ�¹ؿ����
	static void music(string m);//�����ļ���������
};