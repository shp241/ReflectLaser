#include "DoubleMirror.h"

DoubleMirror::DoubleMirror(RelativePoint* p, int angle) :Item(p, false, angle) {}

string DoubleMirror::getImage()const {
	return "Block\\Item\\DoubleMirror\\DoubleMirror_" + to_string(this->getAngle());
}