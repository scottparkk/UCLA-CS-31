#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

// --DECLARING FUNCTION HEADERS----------------------------------------------------------------------------------------------------

bool isValidQC(string results); // True if string follows all parameters are met

int extractNumber(string results, size_t& index, bool& isValid); // string to # (thank you Huang <3)
//For any of the following functions, return -1 if the parameter is not valid

int passQC(string results); // Returns # of pass test results from ALL batches

int defectQC(string results);// Returns the # of defects from ALL batches

int totalQC(string results);//Returns total # of tests from ALL batches

int batches(string results);//Returns # of batches in the string

//--------------------------------------------------------------------------------------------------------------------------------
int main() {
	assert(isValidQC("") == false);
	assert(isValidQC("  ") == false);
	assert(isValidQC("Q0") == false);
	assert(isValidQC("R1") == false);
	assert(isValidQC("Q1p1d0") == true);
	assert(isValidQC("Q1f1d0") == false);
	assert(isValidQC("Q1d1p0") == true);
	assert(isValidQC("Q2f1d1") == false);
	assert(isValidQC("Q2p1d1") == true);
	assert(isValidQC("Q10p5d5") == true);
	assert(isValidQC("Q2p0d2") == true);
	assert(isValidQC("Q2pd") == false);
	assert(isValidQC("Q22p22d0") == true);
	assert(isValidQC("Q2p0d0") == false);
	assert(isValidQC("Q2p00001d0001") == false);
	assert(isValidQC("Q2p0") == false);
	assert(isValidQC("Q1p0d1 akswld") == false);
	assert(isValidQC("Q1p0p1") == false);
	assert(isValidQC("Q1d1d0") == false);
	assert(isValidQC("Q1p1d0Q1p0d1") == true);
	assert(isValidQC("Q20p2d18Q1d1p0Q12p1d11") == true);
	assert(isValidQC("Q1000p500d500Q1d0p1") == true);
	assert(isValidQC("Q100p20d80 ") == false);
	assert(isValidQC("Q26p13d13Q12d5p1") == false);
	assert(isValidQC("Q12p12") == false);
	assert(isValidQC("Q100p50d50Q10d5p5") == true);

	assert(totalQC("Q2p1d1") == 2);
	assert(totalQC("Q100p50d50") == 100);
	assert(totalQC("Q2p1d1Q3p2d1") == 5);
	assert(totalQC("Q23p21d2Q20p0d0") == -1);

	assert(batches("Q2p1d1") == 1);
	assert(batches("Q1p1d0Q100p50d50") == 2);
	assert(batches("Q1p0d1 wldm") == -1);

	assert(passQC("Q2p2d0") == 2);
	assert(passQC("Q2p2d0Q10p5d5") == 7);
	assert(passQC("Q2d1p1Q7d2p5") == 6);
	assert(passQC("Q20p20d0Q10d5p5") == 25);
	assert(passQC("Q209p109d100Q33p23d10") == 132);
	assert(passQC("Q3268p2049d1219") == 2049);
	assert(passQC("Q2862d2200p662") == 662);

	assert(defectQC("Q2p0d2") == 2);
	assert(defectQC("Q3p0d3Q12d4p8") == 7);
	assert(defectQC("Q2p0d2Q4p1d3") == 5);

	return 0;
	

}

bool isValidQC(string results) {
	string digitstring;
	size_t ind = 0;
	bool Valid = true;
	string s;
	int numQ = 0;
	int num1 = 0;
	int num2 = 0;
	size_t howLong = 0;
	int digitsInQ = 0;// digits in Q besides the first digit
	int digitsInFirst = 0; // digits in first p or d besides first digit
	int digitsInSecond = 0; // digits in second p or d besides the first digit
	
	if (results == "") // if the QC test string is empty, return false
		return false;
	else if (results[0] != 'Q')// If QC test doesn't begin with Q, return false
		return false;
	else if ((extractNumber((s += results[1]),ind, Valid)) <= 0)// if the number following Q is less than or equal to 0, return false
		return false;

	for (int i = 2; results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
		|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
		digitsInQ += 1; // again, this calculates the digits after Q (-1 digit)
	}
	if (results[2 + digitsInQ] != 'p' && results[2 + digitsInQ] != 'd') // p and d are only valid characters after first number
		return false;
	else if (results[3 + digitsInQ]!= '1' && results[3 + digitsInQ]!= '2' && results[3 + digitsInQ]!= '3' && results[3 + digitsInQ]!= '4'
		&& results[3 + digitsInQ]!= '5' && results[3 + digitsInQ]!= '6' && results[3 + digitsInQ]!= '7' && results[3 + digitsInQ]!= '8'
		&& results[3 + digitsInQ]!= '9' && results[3 + digitsInQ]!= '0')
		// a number greater than or = 0 must follow p or d
		return false;

	for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
		|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
		digitsInFirst += 1; // calculates digits after the first p or d (-1 digit)
	}
	if (results[4 + digitsInQ + digitsInFirst] != 'p' && results[4 + digitsInQ + digitsInFirst] != 'd') // return false if p or d doesn't follow second set of digits
		return false;
	else if (digitsInFirst >= 1 && results[3 + digitsInQ] == '0')// NO LEADING 0s IN NUMBER FOLLOWING FIRST p OR d
		return false;
	else if (results[5 + digitsInQ + digitsInFirst] != '1' && results[5 + digitsInQ + digitsInFirst] != '2' && results[5 + digitsInQ + digitsInFirst] != '3' 
		&& results[5 + digitsInQ + digitsInFirst] != '4' && results[5 + digitsInQ + digitsInFirst] != '5' && results[5 + digitsInQ + digitsInFirst] != '6' 
		&& results[5 + digitsInQ + digitsInFirst] != '7' && results[5 + digitsInQ + digitsInFirst] != '8' && results[5 + digitsInQ + digitsInFirst] != '9' 
		&& results[5 + digitsInQ + digitsInFirst] != '0')
		// a number greater than 0 must follow the second p or d
		return false;

	for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
		|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
		digitsInSecond += 1; // calculates digits after the second p or d (-1 digit)
	}
	if (digitsInSecond >= 1 && results[5 + digitsInQ + digitsInFirst] == '0')// NO LEADING 0s IN NUMBER FOLLOWING second p OR d
		return false;
	
	numQ = stoi(results.substr(1, (1 + digitsInQ)));//Represents number of Q
	num1 = stoi(results.substr((3 + digitsInQ), (1 + digitsInFirst))); // represents first value given ( p or d)
	num2 = stoi(results.substr((5 + digitsInQ + digitsInFirst), (1 + digitsInSecond)));// second value ( p or d)
	//Tried this with extractNumbers and it didnt work, so I used stoi instead

	if (numQ != num1 + num2)// Make sure that Total tests is = to number of pass + defects
		return false;
	howLong = results.size(); // the total digits in the string/ it's length
	if (results[6 + digitsInQ + digitsInFirst + digitsInSecond] != 'Q' && (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond)) != 0)
		return false; // In order to prevent other random characters following the test string
	else if (results[2 + digitsInQ] == 'p' && results[4 + digitsInQ + digitsInFirst] == 'p') // must contain both p and d
		return false;
	else if (results[2 + digitsInQ] == 'd' && results[4 + digitsInQ + digitsInFirst] == 'd') // must contain both p and d
		return false;
	else if (results[6 + digitsInQ + digitsInFirst + digitsInSecond] == 'Q' && (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond)) > 0)
		// THIS IS THE LOOP
		return isValidQC(results.substr((6 + digitsInQ + digitsInFirst + digitsInSecond), (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond))));
	else 
		return true;

}

int passQC(string results) {
	if (isValidQC(results) == true) {
		string s;
		int a = 0;
		int howManyP = 0;
		int digitsInQ = 0;
		int digitsInP = 0;
		int digitsInD = 0;
		int digitsInFirst = 0;
		int digitsInSecond = 0;

		size_t howLong;
		for (int i = 2; results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInQ += 1; // again, this calculates the digits after Q (-1 digit)
		}
		for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInFirst += 1; // calculates digits after the first p or d (-1 digit)
		}
		for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInSecond += 1; // calculates digits after the second p or d (-1 digit)
		}
		if (results[2 + digitsInQ] == 'p') {
			for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInP += 1; // calculates digits after p if before d(-1 digit)
			}
			a = 3;
		}
		else {
			for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInD += 1; // calculates digits after  d if before p(-1 digit)
			}
			a = 5 + digitsInFirst;
		}
		if (results[4 + digitsInQ + digitsInFirst] == 'p') {
			for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInP += 1; // calculates digits after p if after d(-1 digit)
			}

		}
		else {
			for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInD += 1; // calculates digits after d if after p(-1 digit)
			}
		}
	
		howLong = results.size(); // the total digits in the string/ it's length
		howManyP = stoi(results.substr((a + digitsInQ), (1 + digitsInP)));
		if (results[6 + digitsInQ + digitsInFirst + digitsInSecond] == 'Q' && (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond)) > 0)
			return howManyP + passQC(results.substr((6 + digitsInQ + digitsInFirst + digitsInSecond), (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond))));

		return howManyP;
	}
	else 
		return -1;
}

int defectQC(string results) {
	if (isValidQC(results) == true) {
		string s;
		int a = 0;
		int howManyD = 0;
		int digitsInQ = 0;
		int digitsInP = 0;
		int digitsInD = 0;
		int digitsInFirst = 0;
		int digitsInSecond = 0;

		size_t howLong;
		for (int i = 2; results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInQ += 1; // again, this calculates the digits after Q (-1 digit)
		}
		for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInFirst += 1; // calculates digits after the first p or d (-1 digit)
		}
		for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInSecond += 1; // calculates digits after the second p or d (-1 digit)
		}
		if (results[2 + digitsInQ] == 'd') {
			for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInD += 1; // calculates digits after d if before p(-1 digit)
			}
			a = 3;
			
		}
		else {
			for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInP += 1; // calculates digits after p if before d(-1 digit)
			}
			a = 5 + digitsInFirst;
		}
		if (results[4 + digitsInQ + digitsInFirst] == 'd') {
			for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInD += 1; // calculates digits after d if after p(-1 digit)
			}
		}
		else {
			for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
				|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
				digitsInP += 1; // calculates digits after p if after d(-1 digit)
			}
		}

		howLong = results.size(); // the total digits in the string/ it's length
		howManyD = stoi(results.substr((a + digitsInQ), (1 + digitsInD)));
		if (results[6 + digitsInQ + digitsInFirst + digitsInSecond] == 'Q' && (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond)) > 0)
			return howManyD + defectQC(results.substr((6 + digitsInQ + digitsInFirst + digitsInSecond), (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond))));

		return howManyD;
	}
	else
		return -1;
}

int totalQC(string results) {
	if (isValidQC(results) == true) {
		string s;
		int howManyQ;
		int digitsInQ = 0;
		int digitsInFirst = 0;
		int digitsInSecond = 0;
		size_t howLong;
		for (int i = 2; results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInQ += 1; // again, this calculates the digits after Q (-1 digit)
		}
		for (int i = (4 + digitsInQ); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInFirst += 1; // calculates digits after the first p or d (-1 digit)
		}
		for (int i = (6 + digitsInQ + digitsInFirst); results[i] == '1' || results[i] == '2' || results[i] == '3' || results[i] == '4' || results[i] == '5' || results[i] == '6'
			|| results[i] == '7' || results[i] == '8' || results[i] == '9' || results[i] == '0'; i++) {
			digitsInSecond += 1; // calculates digits after the second p or d (-1 digit)
		}
		howLong = results.size(); // the total digits in the string/ it's length
		howManyQ = stoi(results.substr(1, 1 + digitsInQ));

		if (results[6 + digitsInQ + digitsInFirst + digitsInSecond] == 'Q' && (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond)) > 0)
			return howManyQ + totalQC(results.substr((6 + digitsInQ + digitsInFirst + digitsInSecond), (howLong - (6 + digitsInQ + digitsInFirst + digitsInSecond))));

		return howManyQ;
	}
	else
		return -1;
}

int batches(string results) {
	if (isValidQC(results) == true) {
		int batchNumber = 0;
		for (size_t i = 0; i < results.size(); ++i) {
			if (results[i] == 'Q')// Count every Q ( aka every batch )
				batchNumber = batchNumber + 1;
		}
		return batchNumber;
	}
	else
		return -1;
}

int extractNumber(string results, size_t& index, bool& isValid)
{
	// track the integer value found
	int quantity(0);
	// the result isn't valid until we actually extract atleast one digit!
	isValid = false;
	// don't go beyond the string!
	if (index < results.length())
	{
		// the number can't start with a zero!
		if (results[index] >= '1' && results[index] <= '9')
		{
			// the number should be made up of digits
			while (index < results.length() && isdigit(results[index]))
			{
				// extract one digit and add it to the cumulative value held in quantity
					int digit = results[index] - '0';
				quantity = quantity * 10 + digit;
				index = index + 1;
				isValid = true;
			}
		}
		else
		{
			isValid = false;
		}
	}
	else
	{
		isValid = false;
	}
	return(quantity);
}