#ifndef BLOOD_TYPE
#define BLOOD_TYPE
#include <string>
using namespace std;

#include "BloodDonation.h" 

class BloodType {
public:
	
	// CONSTRUTORS
	BloodType();
	BloodType(int EmployeeID);
	BloodType(int EmployeeID, char type);

	//GETTERS
	int getID();
	char getType();
	double getBonus();


	//SETTERS
	void setType(char type);
	bool bonusType(BloodType donation);

private:
	int mID;
	char mType;
	double mBonus = 0;
};


#endif
