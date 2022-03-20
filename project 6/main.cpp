#include <iostream>
#include <string>
#include <cassert>

#include "VacationAccount.h"
#include "BloodDonation.h"
#include "BloodType.h"
#include "Vampire.h"

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


    VacationAccount account100(314122);
    BloodDonation doner100(314122, 56, 164.77);
    assert(account100.addVacationToAccount(doner100) == true);
    assert(account100.getBalance() == 4.000000);
    assert(account100.bonusHours(doner100) == true);
    assert(account100.getBalance() == 14.000000);

    VacationAccount account101(315122);
    BloodDonation doner101(315122, 35, 141.07);
    assert(account101.addVacationToAccount(doner101) == true);
    assert(account101.getBalance() == 4.000000);
    assert(account101.bonusHours(doner101) == false);
    assert(account101.getBalance() == 4.000000);

    VacationAccount account102(315);
    BloodDonation doner102(315, 59, 142.18);
    assert(account102.addVacationToAccount(doner102) == false);
    assert(account102.getBalance() == 0.000000);
    assert(account102.bonusHours(doner102) == false);
    assert(account102.getBalance() == 0.000000);

    BloodType unknown(123456);
    BloodType typeA(123456, 'a');
    BloodType typeB(654321, 'b');
    BloodType typeO(123456, 'o');
    BloodType invalid(12345, 'o');

    Vampire typeU('u');
    Vampire typeAA('a');

    assert(unknown.getType() == 'u');
        // tests when BloodType is given 1 parameter, mType should be set to u ( unknown )
    assert(unknown.getBonus() == 0);
        // tests getBonus when the blood type is unknown, there should be no bonus
    assert(unknown.bonusType(typeA) == false);
        // tests bonusType with a bloodtype of a, so a bonus is not received and we return false
    assert(unknown.bonusType(typeB) == false);
        // tests bonusType with a bloodtype of b, so a bonus is not received and we return false
    assert(unknown.bonusType(typeO) == true);
        // tests bonusType with a bloodtype of o, so a bonus IS received and we return true
    assert(typeB.getBonus() == 0.000000);
        // testing getBonus with bloodtype b, so mBonus should equal 0
    assert(typeO.bonusType(typeO) == true);
        // a bloodtype of o is a valid bonus bloodtype, so we return true
    assert(typeO.getBonus() == 100.000000);
        // Again, blood type of o received a bonus, so mBonus received 100 ($)
    assert(invalid.bonusType(typeO) == false);
        // If the ID doesn't match the stored mID, we return false, even with blood type o

    assert(typeU.possibleVampire(typeO) == false );
        // type o for blood is NOT the type for a possible vampire, so we return false
    assert(typeU.possibleVampire(typeA) == false);
        // type a for blood is NOT the type for a possible vampire, so we return false
    assert(typeU.possibleVampire(unknown) == true);
        // type u for blood IS the type for a possible vampire, so we return true
    assert(typeU.getVampire() == true);
        // testing getVampire for type U blood type, therefore the stored mVampire should equal true
    assert(typeAA.possibleVampire(unknown) == false);
        // testing possibleVampire where mType is not equal to the given type, so we return false
    assert(typeAA.getVampire() == false);  
        // testing getVampire for type a blood type, therefore the stores mVampire should equal false
    



    cout << "yuh get into it"; // should output this message if asserts work :)

}