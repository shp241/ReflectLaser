#pragma once
#pragma comment(lib,"winmm.lib")//导入声音头文件库
#include <ctime>
#include <list>
#include <stdio.h>
#include <windows.h>
#include "mmsystem.h"//导入声音头文件
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
	static Level* levels[12];//存储所有关卡
	static list<Button*> buttons;//按钮容器
	static Level* game;//指示当前进行的游戏
	static int chapters;//指示当前进行的关卡
	static bool musicOn;//指示背景音乐开关
	static void initialize();//初始化
	static void add(Button* x);//向容器中添加按钮
	static void clear();//清空容器中所有按钮
	static void system();//执行程序主功能
	static void forButtons();//检测鼠标点击按钮的主循环
	static void refresh();//刷新关卡里的
	static void music(string m);//播放文件名的音乐
	static void resetLevel();//重置关卡
};

class MainMenu :public Button {
public:
	MainMenu(Point* p0, Point* p1);
	void role();
	~MainMenu() = default;
};//主菜单按钮

class Start :public Button {
public:
	Start(Point* p0, Point* p1);
	void role();
	~Start() = default;
};//开始游戏按钮

class Option :public Button {
public:
	Option(Point* p0, Point* p1);
	void role();
	~Option() = default;
};//选项按钮

class Music :public Button {
private:
	string music;//该按钮存放的音乐
public:
	Music(Point* p0, Point* p1, string music);
	virtual void role();
	~Music() = default;
};//音乐按钮

class Help :public Button {
public:
	Help(Point* p0, Point* p1);
	void role();
	~Help() = default;
};//帮助按钮

class Exit :public Button {
public:
	Exit(Point* p0, Point* p1);
	void role();
	~Exit() = default;
};//退出按钮

class Chapter :public Button {//关卡按钮点击
private:
	int chapters;//关卡编号
public:
	Chapter(Point* p0, Point* p1, int chapters);
	void role();
	~Chapter() = default;
};

class Rotate :public Button {//旋转按钮点击
private:
	bool clocked;//是否是顺时针
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