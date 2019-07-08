<<<<<<< HEAD
#include "DoubleMirror.h"

DoubleMirror::DoubleMirror(RelativePoint* p, int angle = 0) :Item(p, false, angle) {}

string DoubleMirror::getImage()const {
	return "Block\\Item\\DoubleMirror\\DoubleMirror_" + to_string(this->getAngle());
=======
#include "DoubleMirror.h"

DoubleMirror::DoubleMirror(RelativePoint* p, int angle = 0) :Item(p, false, angle) {}

string DoubleMirror::getImage()const {
	return "Block\\Item\\DoubleMirror\\DoubleMirror_" + to_string(this->getAngle());
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
}