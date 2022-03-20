#include <iostream>
using namespace std;
#include <string>

int main()
{
	string name, month;
	float amount;
	int day, year;

	// get the state name
	cout << "State Name: ";
	getline(cin, name);

	// get the purchase amount 
	cout << "Purchase amount: ";
	cin >> amount;
	// add this so when you insert a string into purchase amount, it says invalid purchase amount
	cin.clear();
	cin.ignore(1000000, '\n');

	// get the month
	cout << "Provide the month: ";
	getline(cin, month);

	// get the day
	cout << "Provide the day: ";
	cin >> day;
	cin.clear();
	cin.ignore(100000, '\n');

	// get the year
	cout << "Provide the year: ";
	cin >> year;
	cin.clear();
	cin.ignore(100000, '\n');

	// if the state name isn't correct (capitilized and spelling), ouput "invalid amount"
	if ((name != "Alabama") && (name != "Alaska") && (name != "Arizona") && (name != "Arkansas")
		&& (name != "California") && (name != "Colorado") && (name != "Connecticut")
		&& (name != "Delaware") && (name != "Florida") && (name != "Georgia") && (name != "Hawaii")
		&& (name != "Idaho") && (name != "Illinois") && (name != "Indiana") && (name != "Iowa")
		&& (name != "Kansas") && (name != "Kentucky") && (name != "Louisiana") && (name != "Maine")
		&& (name != "Maryland") && (name != "Massachusetts") && (name != "Michigan")
		&& (name != "Minnesota") && (name != "Mississippi") && (name != "Missouri") && (name != "Montana")
		&& (name != "Nebraska") && (name != "Nevada") && (name != "New Hampshire")
		&& (name != "New Jersey") && (name != "New Mexico") && (name != "New York")
		&& (name != "North Carolina") && (name != "North Dakota") && (name != "Ohio")
		&& (name != "Oklahoma") && (name != "Oregon") && (name != "Pennsylvania")
		&& (name != "Rhode Island") && (name != "South Carolina") && (name != "South Dakota")
		&& (name != "Tennessee") && (name != "Texas") && (name != "Utah") && (name != "Vermont")
		&& (name != "Virginia") && (name != "Washington") && (name != "West Virginia")
		&& (name != "Wisconsin") && (name != "Wyoming")) {
		cout << "Invalid state!";
	}

	// If the amount isn't greater than 0, then output "invalid amount"
	else if (amount <= 0) {
		cout << "Invalid amount!";
	}

	// If the month isn't a valid month (spelling + capitilized too) then output error message
	else if ((month != "January") && (month != "February") && (month != "March") && (month != "April")
		&& (month != "May") && (month != "June") && (month != "July") && (month != "August")
		&& (month != "September") && (month != "October") && (month != "November")
		&& (month != "December")) {
		cout << "Invalid month!";
	}

	// If the day isn't between 1 and 31 then (inclusive) then output error message
	else if ((day < 1) || (day > 31)) {
		cout << "Invalid day!";
	}
	
	//If the year isn't between 1 and 2025 (inclusive) then output error message
	else if ((year < 1) || (year > 2025)) {
		cout << "Invalid year!";
	}

	// Calculate the total amount for Alabama
	else if (name == "Alabama") {
		// July 15 16 and 17 are tax free
		if ((month == "July") && ((day == 15) || (day == 16) || (day == 17))) { 
			// ANY TIME YOU SEE THIS FOLLOWING 2 LINES, WE LIMIT THE OUTPUT TO 2 DECIMAL POINTS!
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {// for the non tax free dates, we use this else statement
			cout.setf(ios::fixed);
		    cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.04 + .0514); // calculating tax amount and outputting
		}
	}
	
	// Calculate the total amount for Alaska
	else if (name == "Alaska") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0143);
	}

	// Calculate the total amount for Arizona
	else if (name == "Arizona") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0560 + .0277);
	}

	// Calculate the total amount for Arkansas
	else if (name == "Arkansas") {
		// August 6 and 7 are tax free days
		if ((month == "August") && ((day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.065 + .0293);
		}
	}

	// Calculate the total amount for California
	else if (name == "California") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0725 + .0131 + .01);
	}

	// Calculate the total amount for Colorado
	else if (name == "Colorado") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.029 + .0473);

	}

	// Calculate the total amount for Connecticut
	else if (name == "Connecticut") {
		// August 21-27 are tax free days
		if ((month == "August") && ((day == 21) || (day == 22)||(day == 23) || (day == 24)|| (day==25)||(day == 26)||(day==27))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else { // This calcuates taxes for every day other than tax free in Connecticut
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0635);
		}
	}

	// Calculate the total amount for Delaware, Montana, New Hampshire, and Oregon
	// They're all tax free! so we can include them in a single else if statement
	else if ((name == "Delaware") || (name == "Montana") || (name == "New Hampshire") || (name == "Oregon")) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount;
	}

	// Calculate the total amount for Indiana and Rhode Island ( same )
	else if ((name == "Indiana")||(name == "Rhode Island")) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.07);
	}
	
	// Calculate the total amount for Kentucky and Michigan ( same )
	else if ((name == "Kentucky")||(name == "Michigan")) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.06);
	}

	// Calculate the total amount for Florida
	else if (name == "Florida") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.06 + .0105);
	}

	// Calculate the total amount for Georgia
	else if (name == "Georgia") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.04 + .0329);
	}

	// Calculate the total amount for Hawaii
	else if (name == "Hawaii") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.04 + .0041);
	}
	
	// Calculate the total amount for Idaho
	else if (name == "Idaho") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.06 + .0003);
	}

	// Calculate the total amount for Illinois
	else if (name == "Illinois") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0625 + .0249);
	}

	// Calculate the total amount for Iowa
	else if (name == "Iowa") {
	// August 21-27 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.06 + .0082);
		}
	}

	// Calculate the total amount for Kansas
	else if (name == "Kansas") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.065 + .0217);
	}

	// Calculate the total amount for Louisiana
	else if (name == "Louisiana") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0445 + .05);
	}

	// Calculate the total amount for Maine
	else if (name == "Maine") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.055);
	}

	// Calculate the total amount for Maryland
	else if (name == "Maryland") {
		// August 14-20 are tax free days
		if ((month == "August") && ((day == 14) || (day == 15) || (day == 16) || (day == 17) || (day == 18) || (day == 19) || (day == 20))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.06);
		}
	}

	// Calculate the total amount for Massachusetts
	else if (name == "Massachusetts") {
		// August 14 and 15 are tax free days
		if ((month == "August") && ((day == 14) || (day == 15))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0625);
		}
	}

	// Calculate the total amount for Mississippi
	else if (name == "Mississippi") {
		// July 29 and 30 are tax free days
		if ((month == "July") && ((day == 29) || (day == 30))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.07 + .0007);
		}
	}

	// Calculate the total amount for Missouri
	else if (name == "Missouri") {
		// April 19 - 25 are tax free days
		if ((month == "April") && ((day == 19) || (day == 20) || (day == 21) || (day == 22) || (day == 23) || (day == 24) || (day == 25))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0423 + .039);
		}
	}

	// Calculate the total amount for Nevada
	else if (name == "Nevada") {
		// August 5-7 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0685 + .0129);
		}
	}

	// Calculate the total amount for Ohio
	else if (name == "Ohio") {
		// August 5-7 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0575 + .0142);
		}
	}

	// Calculate the total amount for Oklahoma
	else if (name == "Oklahoma") {
		// August 6-8 are tax free days
		if ((month == "August") && ((day == 6) || (day == 7) || (day == 8))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.045 + .0442);
		}
	}

	// Calculate the total amount for South Carolina
	else if (name == "South Carolina") {
		// August 5-7 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.06 + .0143);
		}
	}

	// Calculate the total amount for Tennessee
	else if (name == "Tennessee") {
		// July 29 -31 are tax free days
		if ((month == "August") && ((day == 29) || (day == 30) || (day == 31))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.07 + .0247);
		}
	}

	// Calculate the total amount for Texas
	else if (name == "Texas") {
		// August 5-7 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.0625 + .0194);
		}
	}

	// Calculate the total amount for West Virginia
	else if (name == "West Virginia") {
		// August 5-7 are tax free days
		if ((month == "August") && ((day == 5) || (day == 6) || (day == 7))) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Please pay a total of $" << amount + amount * (.06 + .0039);
		}
	}

	// Calculate the total amount for Minnesota
	else if (name == "Minnesota") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0688 + .0055);
	}

	// Calculate the total amount for Nebraska
	else if (name == "Nebraska") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.055 + .0135);
	}

	// Calculate the total amount for New Jersey
	else if (name == "New Jersey") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0663 - .0003);
	}

	// Calculate the total amount for New Mexico
	else if (name == "New Mexico") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0513 + .0269);
	}

	// Calculate the total amount for New York
	else if (name == "New York") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.04 + .0449);
	}

	// Calculate the total amount for North Carolina
	else if (name == "North Carolina") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0475 + .0222);
	}

	// Calculate the total amount for North Dakota
	else if (name == "North Dakota") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.05 + .0185);
	}

	// Calculate the total amount for Pennsylvania
	else if (name == "Pennsylvania") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.06 + .0034);
	}

	// Calculate the total amount for South Dakota
	else if (name == "South Dakota") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.045 + .019);
	}

	// Calculate the total amount for Utah
	else if (name == "Utah") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.0595 + .0099 + .0125);
	}

	// Calculate the total amount for Vermont
	else if (name == "Vermont") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.06 + .0018);
	}

	// Calculate the total amount for Virginia
	else if (name == "Virginia") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.053 + .0035 + .01);
	}

	// Calculate the total amount for Washington
	else if (name == "Washington") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.065 + .0267);
	}

	// Calculate the total amount for Wisconsin
	else if (name == "Wisconsin") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.05 + .0044);
	}

	// Calculate the total amount for Wyoming
	else if (name == "Wyoming") {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Please pay a total of $" << amount + amount * (.04 + .0136);
	}

	return 0;
}