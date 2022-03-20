#include "Vampire.h"
//CONSTRUCTOR
Vampire::Vampire(char type) {
	if (type != 'a' && type != 'b' && type != 'o') // if the type isnt a, b, or o then the type is u ( unknown )
		mType = 'u';
	else // if the type is a, b , or o, set mType to respective type
		mType = type;
}
//GETTER
char Vampire::getType() { //returns the private mType 
	return mType;
}
bool Vampire::getVampire() { // returns the private mVampire
	return mVampire;
}
//SETTER
bool Vampire::possibleVampire(BloodType type) {
	if (type.BloodType::getType() != mType) // if the mType and given type don't match, return false
		return false;
	else if (type.BloodType::getType() == 'u') { // else if the type matches, and is unknown type, the return true and set mVampire to true
		mType = 'u';
		mVampire = true;
		return true;
	}
	else
		return false;
}