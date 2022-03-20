#include "VacationAccount.h"

// CONSTRUCTOR
VacationAccount::VacationAccount(int EmployeeID){
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
}

// GETTERS
int VacationAccount::getID(){
	return mID;
}
double VacationAccount::getBalance(){
	return mBalance;
}

// SETTERS
bool VacationAccount::addVacationToAccount(BloodDonation donation) {
	if (donation.BloodDonation::getAge() == -1) // if the Employees age is -1, then return false
		return false;
	else if (donation.BloodDonation::getWeight() == -1)// if the Employees weight is -1, then return false
		return false;
	else if (donation.BloodDonation::getID() == -1) // if the Employees ID is -1, then return false
		return false;
	else if (donation.BloodDonation::getID() != mID)// if the Employees ID Number doesn't match the Vaccation Account ID, then return false
		return false;
	else { // else, add 4 to mBalance and return true
		mBalance += 4;
		return true;
	}
}

bool VacationAccount::bonusHours(BloodDonation donation) {
	if (donation.BloodDonation::getAge() == -1) // if the Employees age is -1, then return false
		return false;
	else if (donation.BloodDonation::getWeight() == -1)// if the Employees weight is -1, then return false
		return false;
	else if (donation.BloodDonation::getID() == -1) // if the Employees ID is -1, then return false
		return false;
	else if (donation.BloodDonation::getID() != mID)// if the Employees ID Number doesn't match the Vaccation Account ID, then return false
		return false;
	else if (donation.BloodDonation::getAge() >= 55) {
		mBalance += 10;
		return true;
	}
	else
		return false;	
}