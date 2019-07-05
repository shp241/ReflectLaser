#pragma once
#include<list>
#include"Button.h"

std::list<Button*> buttons;//°´Å¥ÈÝÆ÷
std::list<Button*>::iterator i;

void add(Button* x);
void clear();