#ifndef BLOOD_H
#define BLOOD_H

class BloodDonation
{
public:
	// THE CONSTRUCTOR
	BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight);

	// GETTERS
	int getID();
	int getAge();
	double getWeight();

	// SETTERS
	void setID(int EmployeeID);
	void setAge(int EmployeeAge);
	void setWeight(double EmployeeWeight);

private:
	int mID;
	int mAge;
	double mWeight;
};

#endif
