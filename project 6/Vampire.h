#ifndef VAMPIRE
#define VAMPIRE

#include "BloodType.h" 


class Vampire {
public:
	// CONSTRUTOR
	Vampire(char type);

	//GETTERS
	char getType();
	bool getVampire();

	//SETTERS
	bool possibleVampire(BloodType type);

private:
	bool mVampire = false;
	char mType;
};


#endif
