#include "Time.h"

#include <iostream>
#include <string>

using namespace std;

void assignmentTest();
void testTimeAddition();
void testTimeSubtraction();
//void testTimeRelationalOperators();
//void testTimeOutStreamOperator();
//void testTimeIntegerConversion();

int main() {
	assignmentTest();
	testTimeAddition();
	testTimeSubtraction();
	//testTimeRelationalOperators();
	//testTimeOutStreamOperator();
	//testTimeIntegerConversion();

	return 0;
}

void assignmentTest() {
	Time time1;
	Time time2;

	time2.setDays(21);
	time2.setHours(14);
	time2.setMinutes(06);
	time2.setSeconds(55);

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

//void testTimeRelationalOperators() {
//
//}
//
//void testTimeOutStreamOperator() {
//
//}
//
//void testTimeIntegerConversion() {
//
//}