#include"menu.h"
#include<easyx.h>
#include<graphics.h>
#include"button.h"
#include"menu_operate.h"

void menu() {

  Picture p1;

  p1.initgraph();

  
  Button* start=new Button(new Point(1,2),new Point(,));
  Button* option=new Button(new Point(1, 2), new Point(, ));
  Button* help=new Button(new Point(1, 2), new Point(, ));
  Button* exit=new Button(new Point(1, 2), new Point(, ));
    
  MOUSEMSG m;
  m = GetMouseMsg();  

  
  if (start->if_click(m.x,m.y)) {
    start();
  }//鼠标点击开始游戏
  
  if (option->if_click(m.x,m.y)) {
    option();
  }//选项

  if (help->if_click(m.x, m.y)) {
    help();
  }//帮助

  if (exit->if_click(m.x, m.y)) {
    exit();
  }//退出


}