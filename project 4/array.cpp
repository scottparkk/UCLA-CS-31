#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

//--DECLARE FUNCTION HEADERS-------------------------------------------------------------------------------------------------------------------------

int locateMaximum(const string array[], int n);//returns the index of largest item found in the array, or -1 if n <= 0
int countFloatingPointValues(const string array[], int n);//returns number of floating point numbers, or -1 if n <= 0
bool hasNoCapitals(const string array[], int n);// If any item of the array has a captial letter, return false, else true ( also true if n <= 0)
int shiftLeft(string array[], int n, int amount, string placeholder);//shift all of its elements left by amount, filling in the right-most
	//values with the placeholder value and return the number of times the placeholder value was used or return -1 if n <= 0 or amount < 0

//---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	string a[7] = {"ILove", "You", "Professor Huang","And", "IReally", "Like", "Zombies"};
	string b[5] = { "1000", "20000","300","400","5000" };
	string c[7] = { "Chloe","Kim","is","a great athlete","120","zap","900" }; 
	string d[6] = { "20.1", ".12","2.2.2",".", "+12","00000.1"};
	string e[3] = { "alphabet","soup","YUMMY" };

	assert(locateMaximum(a,4) == 1);
	assert(locateMaximum(a, -2) == -1);
	assert(locateMaximum(a, 7) == 6);
	assert(locateMaximum(b, 3) == 2);
	assert(locateMaximum(c, 7) == 5);

	assert(countFloatingPointValues(a, 7) == 0);
	assert(countFloatingPointValues(b, -1) == -1);
	assert(countFloatingPointValues(c, 7) == 2);
	assert(countFloatingPointValues(d, 6) == 4);
	assert(countFloatingPointValues(d, 3) == 2);

	assert(hasNoCapitals(a, 7) == false);
	assert(hasNoCapitals(b, 4) == true);
	assert(hasNoCapitals(c, 0) == true);
	assert(hasNoCapitals(e, 3) == false);
	assert(hasNoCapitals(e, 2) == true);

	assert(shiftLeft(a, 5, 2, "WAGABOO") == 2);
	assert(shiftLeft(b, 3, 4, "Fill") == 3);
	assert(shiftLeft(c, 2, 20, "yuh") == 2);
	assert(shiftLeft(d, -1, 10, "poop") == -1);
	assert(shiftLeft(e, 2, -3, "ok") == -1);

	return 0;
}
int locateMaximum(const string array[], int n) {
	string curMax = "";
	int index = 0;
	if (n <= 0) // if n is less than or equal to 0, return -1
		return -1;
	else { 
		for (int i = 0; i < n; i++) { // loop n elements through the array
			if (array[i] > curMax) { //  if the index i of the array is greater than the current max, the new current max is that value of the array
				index = i; // the index value of the current max
				curMax = array[index]; // what the current maximum of the array is while looping
			}
		}
		return index;
	}
}

int countFloatingPointValues(const string array[], int n) {
	if (n <= 0) // if n is less than or equal to 0, then the result is true
		return -1;
	else {
		int countNum = 0;
		for (int i = 0; i < n; i++) { // loop n elements through the array
			int countDecimals = 0, valid = 0;
			for (size_t k = 0; k < (array[i]).size(); k++) {// loop through each char of the string
				if (!isdigit(array[i][k]) && array[i][k] != '.') // if the char is neither a digit or a '.' then add 1 to valid
					valid += 1;
				if (array[i][k] == '.') // if the char is '.' add 1 to countDecimals
					countDecimals += 1;
			}
			if (valid == 0 && countDecimals <= 1) // In order to be a Float, it must be a valid digit (check valid variable) and have only 1 or 0 '.'
				countNum += 1;

		}
		return countNum; // return amount of Float values
	}
}

bool hasNoCapitals(const string array[], int n) {
	int result = 0;
	if (n <= 0)// if n is less than or equal to 0, then the result should be true
		return true;

	else {
		for (int i = 0; i < n; i++) { //loop through n elements of the array
			for (size_t k = 0; k < (array[i]).size(); k++) {// loop through each char of the string
				if ((array[i])[k] >= 65 && (array[i])[k] <= 90) // if the ASCII Value isn't matched to a capital letter ( A-Z), then result +1
					result += 1;
			}
		}
	}
	if (result > 0) // if the result is greater than 0, return false ( Meaning there was a capital letter)
		return false;
	else // no capital letters, then return true
		return true;
	
}

int shiftLeft(string array[], int n, int amount, string placeholder) {
	if (n <= 0 || amount < 0) // if n is less than or equal to 0 OR the amount is less than 0, return -1
		return -1;
	else {
		for (int i = 0; i < n; i++) { // to loops over the array through n elements
			if (i + amount >= n) // fill [amount] number of placeholders on the right side of the elements up to n
				array[i] = placeholder;
			else// shift the rest of the elements left by [amount]
				array[i] = array[i + amount];
		}
        if (amount > n) //  if the amount is greater than n, return n
            return n;
        else// otherwise, the return value should just be amount [ the amount of placeholders used]
            return amount;
	}
}