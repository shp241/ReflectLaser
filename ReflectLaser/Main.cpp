#include "System.h"
#include "DoubleMirror.h"
#include "Emitter.h"
#include "HalfMirror.h"
#include "Mirror.h"
#include "Target.h"
#include "Wall.h"

void createLevel() {
	Map* m1 = new Map();
	Item* i1[3] = { new Mirror(), new Mirror(), new Mirror() };
	Level* l1 = new Level(m1, i1, 3);
	l1->addEmitter(new Emitter(new RelativePoint(3, 8), new Colour(Colour::COLOUR_RED), 2));
	l1->addEmitter(new Emitter(new RelativePoint(12, 6), new Colour(Colour::COLOUR_BLUE), 6));
	l1->addTarget(new Target(new Colour(Colour::COLOUR_BLUE), new RelativePoint(7, 9)));
	l1->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(7, 9)));
	l1->saveFile("Level_0");
}

int main() {
	//createLevel();
	System::system();
	return 0;
}