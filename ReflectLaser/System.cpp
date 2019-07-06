#include <easyx.h>
#include "Buttons.h"
#include "Menu.h"
#include "System.h"

void system() {
	Menu* menuFirst = new Menu();
	menuFirst->role();
	forButtons();
}
4