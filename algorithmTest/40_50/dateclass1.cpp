#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class myDate {
public:
	myDate(int year = 1582, int month = 1, int day = 1);
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);
	bool isLeapYear() const;
	int getDayOfWeek() const;
	int getDayOfYear() const;
	int getNumHolidays() const;
	int getNumSummerTimeDays()const;
	void printCalendarOfMonth() const;
private:
	int year;
	int month;
	int day;
};

myDate::myDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int myDate::getDayOfMonth() const {
	return day;
}

int myDate::getMonth() const {
	return month;
}

int myDate::getYear() const {
	return year;
}

void myDate::setDayOfMonth(int day) {
	this->day = day;
}

void myDate::setMonth(int month) {
	this->month = month;
}

void myDate::setYear(int year) {
	this->year = year;
}

void myDate::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

bool myDate::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int myDate::getDayOfWeek() const {
	int sum = 5;

	for (int i = 1582; i < year; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			sum += 366;
		else
			sum += 365;
	}
	for (int i = 1; i < month; i++) {
		switch (i) {
		case 2:
			if (isLeapYear())
				sum += 29;
			else
				sum += 28;
			break;
		case 4: case 6: case 9: case 11:
			sum += 30;
			break;
		default:
			sum += 31;
			break;
		}
	}
	sum += day - 1;

	return sum % 7;
}

int myDate::getDayOfYear() const {
	int sum = 1;

	for (int i = 1; i < month; i++) {
		for (int j = 1; j < day; j++) {
			sum++;
		}
	}
	return sum;
}


int main(int argc, char *argv[])
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		int year, month, day;
		inStream >> year >> month >> day;
		myDate date1(year, month, day), date2;

		cout << date1.getYear() << " ";
		cout << date1.getMonth() << " ";
		cout << date1.getDayOfMonth() << endl;
		cout << date1.isLeapYear() << " ";
		cout << date1.getDayOfWeek() << endl;
		inStream >> year >> month >> day;

		date2.setDayOfMonth(day);
		date2.setMonth(month);
		date2.setYear(year);

		cout << date2.getYear() << " ";
		cout << date2.getMonth() << " ";
		cout << date2.getDayOfMonth() << endl;
		cout << date2.isLeapYear() << " ";
		cout << date2.getDayOfWeek() << endl;

		inStream >> year >> month >> day;
		date2.setDate(year, month, day);

		cout << date2.getYear() << " ";
		cout << date2.getMonth() << " ";
		cout << date2.getDayOfMonth() << endl;
		cout << date2.isLeapYear() << " ";
		cout << date2.getDayOfWeek() << endl;
	}
	inStream.close();
}
