#include <iostream>
using namespace std;
bool isLeapYear(size_t year) {
	if (year <= 1916) {
		return year % 4 == 0;
	}
	else {
		if (year % 4 == 0) {
			return true;
		}
		else if (year % 4 == 0 && year % 100 == 0) {
			return false;
		}
		else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
			return true;
		}
	}
}
class Date {
private:
	size_t year;
	size_t month;
	size_t day;
public:
	size_t getYear() {
		return year;
	}
	size_t getMonth() {
		return month;
	}
	size_t getDay() {
		return day;
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

