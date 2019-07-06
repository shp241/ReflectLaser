#pragma once
#include"Button.h"
#include"Picture.h"

void menu();
void start(Picture p);
void option(Picture p);
void help(Picture p);
void exit(Picture p);
void chooseChapter(Picture p);

class Menu :public Button {
public:
	void role();
	Menu() = default;
};

class Start :public Button {
public:
	void role(Picture p);
};

class Option :public Button {
public:
	void role(Picture p);
};

class Help :public Button {
public:
	void role(Picture p);
};

class Exit :public Button {
public:
	void role(Picture p);
};