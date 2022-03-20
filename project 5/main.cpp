#include <iostream>
#include <string>
#include <cassert>

#include "VacationAccount.h"
#include "BloodDonation.h"

using namespace std;

int main()
{

    BloodDonation bloodDoner1(123456, 29, 201.00);
    BloodDonation bloodDoner2(654321, 32, 198.22);
    BloodDonation invalidID(1000000, 28, 222.19);
    BloodDonation invalidAge(123456, 99, 178.56);
    BloodDonation invalidWeight(654321, 55, 23.22);
    VacationAccount testVacation(654321);

    assert(to_string(bloodDoner1.getID()) == "123456");
        // testing getID (mID should change)
    assert(to_string(bloodDoner1.getAge()) == "29");
        // testing getAge (mAge)
    assert(to_string(bloodDoner1.getWeight()) == "201.000000");
        // testing getWeight (mWeight)
    assert(to_string(bloodDoner2.getID()) == "654321");
        // testing getID
    assert(to_string(bloodDoner2.getAge()) == "32");
        // testing getAge
    assert(to_string(bloodDoner2.getWeight()) == "198.220000");
        // testing getWeight
    assert(to_string(invalidID.getID()) == "-1");
        // testing an invalid ID test case
    assert(to_string(invalidAge.getAge()) == "-1"); 
        // testing an invalid Age test case
    assert(to_string(invalidWeight.getWeight()) == "-1.000000");
        // testing an invalid Weight test case
    
    assert(to_string(testVacation.getBalance()) == "0.000000");
        // testing that the initial balance should be 0
    assert(to_string(testVacation.getID())=="654321");
        // testing getID
    assert(testVacation.addVacationToAccount(bloodDoner2) == true);
        // testing a valid ID match with addVacationToAccount
    assert(testVacation.addVacationToAccount(bloodDoner1) == false); 
        // testing an ID mismatch with addVacationToAccount
    assert(to_string(testVacation.getBalance()) == "4.000000");
        // testing that +4 is added to mBalance
    assert(testVacation.addVacationToAccount(invalidID) == false);
        // testing an invalid ID with addVacationToAccount
    assert(testVacation.addVacationToAccount(invalidWeight) == false);
        // testing an invalid Weight with addVacationToAccount
    assert(testVacation.addVacationToAccount(invalidAge) == false);
        // testing an invalid Age with addVacationToAccount

    cout << "yuh get into it"; // should output this message if asserts work :)
}