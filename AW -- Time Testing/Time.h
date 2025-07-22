#ifndef TIME
#define TIME

#include <iostream>

using namespace std;

class Time
{
private:
	int days;
	int hours;
	int minutes;
	int seconds;

public:
	Time();
	Time(int, int, int, int);
	Time(int, int, int);
	Time(int, int);

	int getDays() const;
	void setDays(int);

	int getHours() const;
	void setHours(int);

	int getMinutes() const;
	void setMinutes(int);

	int getSeconds() const;
	void setSeconds(int);

	Time operator+ (const Time&) const;
	Time operator- (const Time&) const;
};

#endif