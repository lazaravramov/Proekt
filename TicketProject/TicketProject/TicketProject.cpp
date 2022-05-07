#include <iostream>
using namespace std;
bool isLeapYear(size_t year) {
	if (year <= 1916) {
		return year % 4 == 0;
	}
	else {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				return false;
			}
			else if (year % 100 == 0 && year % 400 == 0) {
				return true;
			}
			return true;
		}
	}
}
class Date {
private:
	bool isMod;
	size_t year;
	size_t month;
	size_t day;
	size_t days_Max[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void	validateGregCalendar() {
		if (year == 1916 && month == 4 && day >= 1 && day <= 13) {
			day = 14;
		}
	}
public:
	Date(size_t year, size_t month, size_t day) {
		setYear(year);
		setMonth(month);
		setDay(day);
	}
	size_t getYear() {
		return year;
	}
	size_t getMonth() {
		return month;
	}
	size_t getDay() {
		return day;
	}
	void setYear(size_t year) {
		this->year = year;
		if (isLeapYear(year)) {
			days_Max[1] = 29;
		}
		isMod = true;
	}
	void setMonth(size_t month) {
		if (month > 12) {
			month = 1;
		}
		this->month = month;
	}
	void setDay(size_t day) {
		if (day > days_Max[month - 1]) {
			day = 1;
		}
		this->day = day;
		isMod = true;
	}
};
class Hall {
private:
	size_t hallNumber;
	size_t numberOfRows;
	size_t numberOfSeats;
public:
	size_t getHallNumber() {
		return hallNumber;
	}
	size_t getNumberOfRows() {
		return numberOfRows;
	}
	size_t getNumberOfSeats() {
		return numberOfSeats;
	}
};
class Performance {
private:
	Date a;
	char* name;
	void free() {
		delete[] name;
	}
	void copyFrom(const Performance& other) {
		a = other.a;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
public:
	Performance();
	Performance& operator=(const Performance& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	Performance(const Performance& other) {
		copyFrom(other);
	}
	~Performance() {
		free();
	}
};
int main()
{
 
}

