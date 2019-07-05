#include<easyx.h>
#include"Buttons.h"
#include"Menu.h"
#include"System.h"

void system() {
  Menu menu_first;
  
  menu_first.role();

  for (;;) {

    MOUSEMSG m;
    m = GetMouseMsg();

    for (i = buttons.begin(); i != buttons.end(); ++i) {
      if (i->ifClick(m.x, m.y)) {
        i->role();
        break;
      }
    }

    FlushMouseMsgBuffer();//清空鼠标输入缓冲区
  }
}