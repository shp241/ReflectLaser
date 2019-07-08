#pragma once
#include <list>
#include "Button.h"
#pragma comment(lib,"winmm.lib")//导入声音头文件库
#include <stdio.h>
#include <windows.h>
#include "mmsystem.h"//导入声音头文件
#include "Level.h"
#include "Menu.h"
using std::list;

class System {
public:
	static list<Button*> buttons;//按钮容器
	static Level* game;//指示当前进行的游戏
	static bool musicOn;//指示背景音乐开关
	static void initialize();//初始化
	static void add(Button* x);//向容器中添加按钮
	static void rid(Button x);//从容器中去除!某一类型的全部按钮!
	static void clear();//清空容器中所有按钮
	static void system();//执行程序主功能
	static void forButtons();//检测鼠标点击按钮的主循环
	static void refresh();//刷新关卡里的
	static void music(string m);//播放文件名的音乐
};