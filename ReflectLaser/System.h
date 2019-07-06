#pragma once
#include <list>
#include "Button.h"
#include "Menu.h"
using std::list;

namespace System {
	list<Button*> buttons;//按钮容器
	void add(Button* x);//向容器中添加按钮
	void clear();//清空容器中所有按钮
	void system();//执行程序主功能
	void forButtons(Picture* p);//检测鼠标点击按钮的主循环
}