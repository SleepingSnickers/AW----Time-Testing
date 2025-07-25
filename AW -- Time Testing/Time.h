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
	//default constructor
	Time();
	//alternate constructor
	Time(int, int, int, int);
	Time(int, int, int);
	Time(int, int);

	//copy constructor
	Time(const Time&);

	//getters/setters
	int getDays() const;
	void setDays(int);

	int getHours() const;
	void setHours(int);

	int getMinutes() const;
	void setMinutes(int);

	int getSeconds() const;
	void setSeconds(int);

	//bunchhhh of relational operators
	Time& operator= (const Time&);
	Time operator+ (const Time&) const;
	Time operator- (const Time&) const;
	bool operator== (const Time&) const;
	bool operator< (const Time&) const;
	bool operator> (const Time&) const;
	bool operator<= (const Time&) const;
	bool operator>= (const Time&) const;
	//declare ostream a friend
	friend ostream& operator<<(ostream&, const Time&);
	//object converter overload
	operator int() const;
};

#endif