#include "BloodDonation.h"


// THE CONSTRUCTOR
BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight) {
	setID(EmployeeID);
	setAge(EmployeeAge);
	setWeight(EmployeeWeight);
}

// THE GETTERS
int BloodDonation::getID() {
	return mID;
}
int BloodDonation::getAge() {
	return mAge;
}
double BloodDonation::getWeight() {
	return mWeight;
}

// THE SETTERS
void BloodDonation::setID(int EmployeeID) {
	int validID = 0; 
	int holderID = EmployeeID; // keeps track of the given ID

	while (EmployeeID) { // Counts Digits in a number
		EmployeeID /= 10;
		validID++;
	}

	if (validID == 6)  // if there are exactly 6 valid digits, then mID is equal to the employeeID
		mID = holderID;
	else // else, set the employee ID to -1
		mID = -1;
}
void BloodDonation::setAge(int EmployeeAge) {
	int validAge = 0;
	int holderAge = EmployeeAge; // to keep track of actual given Age

	while (EmployeeAge) { // Counts Digits in a Age
		EmployeeAge /= 10;
		validAge++;
	}
	if (validAge == 2 && holderAge >= 21 && holderAge <= 65) // if there exactly 2 valid digits, and the digit are between 21-65, then mAge is equal to employeeAge
		mAge = holderAge;
	else // Else, set the employee age to -1
		mAge = -1;
}
void BloodDonation::setWeight(double EmployeeWeight) {
	if (EmployeeWeight >= 101.00 && EmployeeWeight <= 280.00)// if the Employees weight is greater than 101 and less than 202, set mWeight equal to Employee Weight
		mWeight = EmployeeWeight;
	else // else, set the Employee Weight to -1
		mWeight = -1;
}