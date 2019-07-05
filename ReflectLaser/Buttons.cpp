#include"Buttons.h"
#include"Button.h"
#include<list>


void add(Button* x) {
  buttons.push_back(x);
}

void clear() {
  buttons.clear();
}
