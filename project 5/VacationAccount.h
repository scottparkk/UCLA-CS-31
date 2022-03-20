#ifndef VACATION_H
#define VACATION_H

#include "BloodDonation.h" 

class VacationAccount
{
public:
	// CONSTRUCTOR
	VacationAccount(int EmployeeID);

	// GETTERS
	int getID();
	double getBalance();

	// SETTERS
	bool addVacationToAccount(BloodDonation donation);

private:
	int mID;
	double mBalance = 0;
};

#endif