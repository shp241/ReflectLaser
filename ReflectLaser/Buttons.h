#pragma once
#include<list>
#include"Button.h"

std::list<Button*> buttons;//��ť����
std::list<Button*>::iterator i;

void add(Button* x);
void clear();