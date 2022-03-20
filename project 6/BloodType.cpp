#include "BloodType.h"


//CONSTRUCTORS
BloodType::BloodType() { // constructor w/o arguments (overloading)
	mID = -1;
	mType = 'u';
}
BloodType::BloodType(int EmployeeID) {
	int validID = 0;
	int holderID = EmployeeID; // keeps track of the given ID

	while (holderID) { // Counts Digits in a number
		holderID /= 10;
		validID++;
	}

	if (validID == 6)  // if there are exactly 6 valid digits, then mID is equal to the employeeID
		mID = EmployeeID;
	else // else, set the employee ID to -1
		mID = -1;
	
	mType = 'u';
}
BloodType::BloodType(int EmployeeID, char type) : BloodType::BloodType( EmployeeID) { // CONSTRUCTOR DELEGATION
	setType(type);
}
//GETTERS

int BloodType::getID() {
	return mID;
}
char BloodType::getType() {
	return mType;
}
double BloodType::getBonus() {
	return mBonus;
}

//SETTERS/FUNCTIONS

void BloodType::setType(char type) {
	if (type == 'a' || type == 'b' || type == 'o') // if the type is a, b, or o then the mType should be set to that type respectively
		mType = type;
	else // if the type isn't a, b , or o, set mType to 'u'
		mType = 'u';
	
}

bool BloodType::bonusType(BloodType donation) {

	if (donation.BloodType::getID() == -1) // if the Employees ID is -1, then return false
		return false;
	else if (donation.BloodType::getID() != mID)// if the Employees ID Number doesn't match the Blood Type ID, then return false
		return false;
	else if (donation.BloodType::getType() == 'o') { // if they have o type blood, they get a bonus and return true
		mBonus += 100;
		return true;
	}
	else
		return false;
}