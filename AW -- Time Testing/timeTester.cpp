#include "Time.h"

#include <iostream>
#include <string>

using namespace std;

void assignmentTest();
void testTimeAddition();
void testTimeSubtraction();
void testTimeRelationalOperators();
void testTimeOutStreamOperator();
void testTimeIntegerConversion();

int main() {
	assignmentTest();
	cout << endl;

	testTimeAddition();
	cout << endl;

	testTimeSubtraction();
	cout << endl;

	testTimeRelationalOperators();
	cout << endl;

	testTimeOutStreamOperator();
	cout << endl;

	testTimeIntegerConversion();
	cout << endl;

	return 0;
}

void assignmentTest() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	cout << "Time 1: " << endl;
	cout << "Days: " << time1.getDays() << endl;
	cout << "Hours: " << time1.getHours() << "\nMinutes: " << time1.getMinutes() << "\nSeconds: " << time1.getSeconds() << endl;

	cout << endl;

	cout << "Time 2: " << endl;
	cout << "Days: " << time2.getDays() << endl;
	cout << "Hours: " << time2.getHours() << "\nMinutes: " << time2.getMinutes() << "\nSeconds: " << time2.getSeconds() << endl << endl;

	time1 = time2;

	cout << "Time 1: " << endl;
	cout << "Days: " << time1.getDays() << endl;
	cout << "Hours: " << time1.getHours() << "\nMinutes: " << time1.getMinutes() << "\nSeconds: " << time1.getSeconds() << endl;

	cout << endl;

	cout << "Time 2: " << endl;
	cout << "Days: " << time2.getDays() << endl;
	cout << "Hours: " << time2.getHours() << "\nMinutes: " << time2.getMinutes() << "\nSeconds: " << time2.getSeconds() << endl;
}

void testTimeAddition() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	Time sum = time1 + time2;

	cout << "The sum of time one and time two is " << sum.getDays() << " days, " << sum.getHours() << " hours, " << sum.getMinutes() << " minutes, and " << sum.getSeconds() << " seconds." << endl;
}

void testTimeSubtraction() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	Time difference = time1 - time2;

	cout << "The difference of time one and time two is " << difference.getDays() << " days, " << difference.getHours() << " hours, " << difference.getMinutes() << " minutes, and " << difference.getSeconds() << " seconds." << endl;
}

void testTimeRelationalOperators() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	if (time1 == time2) {
		cout << "Time one == time two" << endl;
	}
	else {
		cout << "Time one != time two" << endl;
	}

	if (time1 < time2) {
		cout << "Time one < time two" << endl;
	}
	else {
		cout << "Time one > time two" << endl;
	}
	
}

void testTimeOutStreamOperator() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	cout << time1 << endl;
	cout << endl;
	cout << time2 << endl;
}

void testTimeIntegerConversion() {
	Time time1(3, 5, 9, 10);
	Time time2(27, 4, 31, 7);

	int totalSecs1 = static_cast<int>(time1);
	int totalSecs2 = static_cast<int>(time2);

	cout << "Days: " << time1.getDays() << endl;
	cout << "Hours: " << time1.getHours() << endl;
	cout << "Minutes: " << time1.getMinutes() << endl;
	cout << "Seconds: " << time1.getSeconds() << endl;
	cout << "Amount of seconds in the time as an int: " << totalSecs1 << endl << endl;

	cout << "Days: " << time2.getDays() << endl;
	cout << "Hours: " << time2.getHours() << endl;
	cout << "Minutes: " << time2.getMinutes() << endl;
	cout << "Seconds: " << time2.getSeconds() << endl;
	cout << "Amount of seconds in the time as an int: " << totalSecs2 << endl << endl;
}