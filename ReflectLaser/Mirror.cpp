<<<<<<< HEAD
#include "Mirror.h"

Mirror::Mirror(RelativePoint* p, int angle = 0) :Item(p, false, angle) {}

string Mirror::getImage()const {
	return "Block\\Item\\Mirror\\Mirror_" + to_string(this->getAngle());
=======
#include "Mirror.h"

Mirror::Mirror(RelativePoint* p, int angle = 0) :Item(p, false, angle) {}

string Mirror::getImage()const {
	return "Block\\Item\\Mirror\\Mirror_" + to_string(this->getAngle());
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
}