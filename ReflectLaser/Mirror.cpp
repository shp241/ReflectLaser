#include "Mirror.h"

Mirror::Mirror(RelativePoint* p, int angle = 0) :Item(p, false, angle) {}

string Mirror::getImage()const {
	return "Block\\Item\\Mirror\\Mirror_" + to_string(this->getAngle());
}