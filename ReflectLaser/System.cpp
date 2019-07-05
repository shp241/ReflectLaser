#include<easyx.h>
#include"Buttons.h"
#include"Menu.h"
#include"System.h"

void system() {
  Menu* menu_first=new Menu();
  
  menu_first->role();
  
  forbuttons();
}