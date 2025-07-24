#include "Time.h"

#include <iostream>

using namespace std;

Time::Time() {
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(int days, int hours, int minutes, int seconds) {
	int total = ((days * 24 + hours) * 60 + minutes) * 60 + seconds;

	this->days = total / 86400;
	total %= 86400;

	this->hours = total / 3600;
	total %= 3600;

	this->minutes = total / 60;
	this->seconds = total % 60;
}

Time::Time(int hours, int minutes, int seconds) : Time(0, hours, minutes, seconds) {

}

Time::Time(int hours, int minutes) : Time(0, hours, minutes, 0) {

}

Time::Time(const Time& time) {
	this->days = time.days;
	this->hours = time.hours;
	this->minutes = time.minutes;
	this->seconds = time.seconds;
}

int Time::getDays() const {
	return days;
}

void Time::setDays(int days) {
	this->days = days;
}

int Time::getHours() const {
	return hours;
}

void Time::setHours(int hours) {
	this->hours = hours % 24;
	this->days += hours / 24;
}

int Time::getMinutes() const {
	return minutes;
}

void Time::setMinutes(int minutes) {
	hours += minutes / 60;
	this->minutes = minutes % 60;
	this->days = this->hours / 24;
	hours %= 24;
}

int Time::getSeconds() const {
	return seconds;
}

void Time::setSeconds(int seconds) {
	this->minutes += seconds / 60;
	this->seconds = seconds % 60;
	this->hours += this->minutes / 60;
	this->minutes %= 60;
	this->days += this->hours / 24;
	hours %= 24;
}

Time& Time::operator= (const Time& right) {
	if (this != &right) {
		this->days = right.days;
		this->hours = right.hours;
		this->minutes = right.minutes;
		this->seconds = right.seconds;
	}
	return *this;
}

Time Time::operator+ (const Time& right) const {
	//convert all the time into seconds to add up
	int value = ((this->days + right.days) * 24 * 60 * 60) + ((this->hours + right.hours) * 60 * 60) + ((this->minutes + right.minutes) * 60) + (this->seconds + right.seconds);

	//find days by dividing totalSecs by the amount of seconds in a day
	int totalDays = value / 86400;
	//find the amount of leftover seconds after removing days
	value %= 86400;

	//find how many hours are left in totalSecs by dividing by the amount of seconds in an hour
	int totalHours = value / 3600;
	//find the amount of leftover seconds after removing hours
	value %= 3600;

	//find how many minutes are left in totalSecs by dividing by the amount of seconds in a minute
	int totalMins = value / 60;
	//find the amount of leftover seconds after removing minutes, no need to %= because the % is already the exact leftover left from taking minutes out
	int totalSecs = value % 60;

	return Time(totalDays, totalHours, totalMins, totalSecs);
}

Time Time::operator- (const Time& right) const {
	int time1Total = ((days * 24 + hours) * 60 + minutes) * 60 + seconds;
	int time2Total = ((right.days * 24 + right.hours) * 60 + right.minutes) * 60 + right.seconds;

	int value = time1Total - time2Total;
	//get the absolute value to ensure only the days can be negative
	int sign = value < 0 ? -1 : 1;
	value = abs(value);

	int totalDays = value / 86400;
	value %= 86400;

	int totalHours = value / 3600;
	value %= 3600;

	int totalMins = value / 60;
	int totalSecs = value % 60;

	return Time(totalDays, totalHours, totalMins, totalSecs);
}

bool Time::operator== (const Time& right) const {
	return this->days == right.days && this->hours == right.hours && this->minutes == right.minutes && this->seconds == right.seconds;
}

bool Time::operator< (const Time& right) const {
	if (days != right.days) return days < right.days;
	if (hours != right.hours) return hours < right.hours;
	if (minutes != right.minutes) return minutes < right.minutes;
	return seconds < right.seconds;
}

bool Time::operator> (const Time& right) const {
	if (days != right.days) return days > right.days;
	if (hours != right.hours) return hours > right.hours;
	if (minutes != right.minutes) return minutes > right.minutes;
	return seconds > right.seconds;
}

bool Time::operator<= (const Time& right) const {
	return !(*this < right);
}

bool Time::operator>= (const Time& right) const {
	return !(*this > right);
}

ostream& operator<<(ostream& out, const Time& right) {
	out << right.getDays() << " days " << right.getHours() << " hours " << right.getMinutes() << " minutes " << right.getSeconds() << " seconds";
	return out;
}

Time::operator int() const {
	return ((this->days * 24 + this->hours) * 60 + this->minutes) * 60 + this->seconds;
}