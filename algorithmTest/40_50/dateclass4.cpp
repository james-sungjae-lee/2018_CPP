#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class myDate {
	// friend 함수
	friend ostream &operator <<(ostream &outStream, const myDate& date);
	friend istream &operator >>(istream &inStream, myDate& date);
	friend myDate operator +(int num, const myDate& date);
public:
	// Constructor (생성자)
	myDate(int year = 1582, int month = 1, int day = 1);
	// Copy Constructor (복사 생성자)
	myDate(const myDate& date);
	// Accessor functions (접근자)
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	// Mutator functions (변경자)
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);
	// Operators overloaded
	int operator -(const myDate& date) const; // difference between two days
	myDate operator +(int num) const;
	myDate operator -(int num) const;
	myDate& operator ++(); // prefix increment
	myDate& operator --(); // prefix decrement
	myDate operator ++(int); // postfix increment
	myDate operator --(int); // postfix decrement
	myDate& operator =(const myDate& date);
	myDate& operator +=(int num);
	myDate& operator -=(int num);
	bool operator >(const myDate& date) const;
	bool operator >=(const myDate& date) const;
	bool operator <(const myDate& date) const;
	bool operator <=(const myDate& date) const;
	bool operator ==(const myDate& date) const;
	bool operator !=(const myDate& date) const;
	// utility functions
	bool isLeapYear() const; //윤년
	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
	int getNumHolidays() const; //휴일수 계산
	int getNumSummerTimeDays()const; //써머타임 날짜수
	void printCalendarOfMonth() const; // 달력출력하기
private:
	// information hiding : implement as you wish
	int year;
	int month;
	int day;
};

myDate::myDate(int year, int month, int day)
	: year(year), month(month), day(day)
{
}
myDate::myDate(const myDate& date)
{
	this->year = date.getYear();
	this->month = date.getMonth();
	this->day = date.getDayOfMonth();
}
// Accessor functions (접근자)
int myDate::getDayOfMonth() const {
	return day;
}
int myDate::getMonth() const {
	return month;
}
int myDate::getYear() const {
	return year;
}
// Mutator functions (변경자)
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
// utility functions
bool myDate::isLeapYear() const {//윤년
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}
int myDate::getDayOfWeek() const { //0=Sunday, 1=Monday, ..., 6=Saturday
	int year = this->year;
	int month = this->month;
	int day = this->day;
	int result = 0;

	if (month <= 2)
	{
		--year;
		month += 12;
	}
	int a = year / 100;
	int b = year % 100;
	result = ((21 * a / 4) + (5 * b / 4) + (26 * (month + 1) / 10) + day - 1) % 7;
	return result;
}

int myDate::getDayOfYear() const {
	int year = this->year;
	int month = this->month;
	int day = this->day;

	for (int i = 1; i < month; i++) {
		switch (i) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day += 30;
			break;
		case 2:
			if (isLeapYear() == true) {
				day += 29;
			}
			else {
				day += 28;
			}
			break;
		default:
			break;
		}
	}
	return day;
}

int myDate::getNumHolidays() const {
	int numHolidays = 0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}

	myDate temp;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= monthDays[i - 1]; j++) {
			temp.setDate(this->year, i, j);
			if (temp.getDayOfWeek() == 0 || temp.getDayOfWeek() == 6) {
				numHolidays++;
			}
		}
	}

	temp.setDate(this->year, 1, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 3, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 5, 5);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 6, 6);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 7, 17);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 8, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 10, 3);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 12, 25);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 2, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 2, 2);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 2, 3);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 5, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 9, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 9, 16);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 9, 17);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	return numHolidays;
}

int myDate::getNumSummerTimeDays() const {
	int numSummerTimeDays = 0;
	myDate march(this->year, 3, 31);
	myDate october(this->year, 10, 31);

	numSummerTimeDays = october.getDayOfYear() - march.getDayOfYear();

	int count = 31;
	while (march.getDayOfWeek() != 0) {
		march.setDate(this->year, 3, count--);
		numSummerTimeDays++;
	}
	if (count == 31) {
		numSummerTimeDays++;
	}
	count = 31;
	while (october.getDayOfWeek() != 0) {
		october.setDate(this->year, 10, count--);
		numSummerTimeDays--;
	}
	if (count == 31) {
		numSummerTimeDays--;
	}

	return numSummerTimeDays;
}

void myDate::printCalendarOfMonth() const {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int days = 0;
	int firstdate = 0;
	int count = 0;

	cout << this->year << " " << this->month << endl;
	days = (year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);

	for (int j = 0; j<month - 1; j++) {
		days += monthDays[j];
	}

	firstdate = days % 7;

	for (int j = 0; j <= firstdate; j++) {
		if (firstdate != 6) {
			cout << 0 << " ";
			count++;
		}
	}
	for (int j = 1; j <= monthDays[month - 1]; j++) {
		if (count >= 7) {
			cout << endl;
			count = 0;
		}
		cout << j << " ";
		count++;
	}

	for (int j = 0; j<7 - count; j++) {
		cout << 0 << " ";
	}
}

ostream &operator <<(ostream &outStream, const myDate& date) {
	outStream << setfill('0') << setw(2) << date.getDayOfMonth()
		<< '/' << setw(2) << date.getMonth() << '/' << date.getYear();

	return outStream;
}

istream &operator >>(istream &inStream, myDate& date) {
	int data[3] = { 0, };
	inStream >> data[0] >> data[1] >> data[2];
	date.setDate(data[0], data[1], data[2]);

	return inStream;
}

myDate operator +(int num, const myDate& date) {
	if (num < 0) {
		myDate temp(date.getYear(), date.getMonth(), date.getDayOfMonth());
		return (temp - -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date.isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = num + date.getDayOfMonth();
	int tempMonth = date.getMonth();
	int tempYear = date.getYear();

	while (tempDay > monthDays[tempMonth - 1]) {
		tempDay -= monthDays[tempMonth - 1];
		tempMonth++;
		if (tempMonth > 12) {
			tempMonth = 1;
			tempYear++;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;
}

int myDate::operator -(const myDate& date) const {
	int tempDay1 = getDayOfYear();
	int tempDay2 = date.getDayOfYear();

	for (int i = year; i < date.getYear(); i++) {
		myDate temp(i, 12, 31);
		tempDay1 -= temp.getDayOfYear();
	}

	for (int i = date.getYear(); i < year; i++) {
		myDate temp(i, 12, 31);
		tempDay2 -= temp.getDayOfYear();
	}

	return tempDay1 - tempDay2;
}

myDate myDate::operator +(int num) const {
	if (num < 0) {
		return (*this - -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = num + getDayOfMonth();
	int tempMonth = getMonth();
	int tempYear = getYear();

	while (tempDay > monthDays[tempMonth - 1]) {
		tempDay -= monthDays[tempMonth - 1];
		tempMonth++;
		if (tempMonth > 12) {
			tempMonth = 1;
			tempYear++;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;

}

myDate myDate::operator -(int num) const {
	if (num < 0) {
		return (*this + -num);
	}
	int monthDays[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = getDayOfMonth() - num;
	int tempMonth = getMonth();
	int tempYear = getYear();

	while (tempDay <= 0) {
		tempMonth--;
		if (tempMonth <= 0) {
			tempMonth = 12;
			tempYear--;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
		tempDay += monthDays[tempMonth - 1];

	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;
}

myDate& myDate::operator ++() {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}


	day++;
	if (day > monthDays[month - 1]) {
		day = 1;
		month++;
	}
	if (month > 12) {
		month = 1;
		year++;
	}

	return *this;
}

myDate& myDate::operator --() {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}

	day--;
	if (day == 0) {
		day = monthDays[month - 2];
		month--;
	}
	if (month == 0) {
		month = 12;
		year--;
	}

	return *this;
}

myDate myDate::operator ++(int) {
	myDate temp = *this;
	++*this;
	return temp;
}

myDate myDate::operator --(int) {
	myDate temp = *this;
	--*this;
	return temp;
}

myDate& myDate::operator =(const myDate& date) {
	day = date.getDayOfMonth();
	month = date.getMonth();
	year = date.getYear();

	return *this;
}

myDate& myDate::operator +=(int num) {
	if (num < 0) {
		return (*this -= -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	day = num + day;

	while (day > monthDays[month - 1]) {
		day -= monthDays[month - 1];
		month++;
		if (month > 12) {
			month = 1;
			year++;
			if (isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	return *this;
}

myDate& myDate::operator -=(int num) {
	if (num < 0) {
		return (*this += -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	day = month - num;

	while (day <= 0) {
		month--;
		if (month <= 0) {
			month = 12;
			year--;
			if (isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
		day += monthDays[month - 1];

	}

	return *this;
}

bool myDate::operator >(const myDate& date) const {
	if (year > date.getYear()) {
		return true;
	}
	else if (year < date.getYear()) {
		return false;
	}

	if (month > date.getMonth()) {
		return true;
	}
	else if (month < date.getMonth()) {
		return false;
	}

	if (day > date.getDayOfMonth()) {
		return true;
	}
	else if (day < date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator >=(const myDate& date) const {
	if (year >= date.getYear()) {
		return true;
	}
	else if (year < date.getYear()) {
		return false;
	}

	if (month >= date.getMonth()) {
		return true;
	}
	else if (month < date.getMonth()) {
		return false;
	}

	if (day >= date.getDayOfMonth()) {
		return true;
	}
	else if (day < date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator <(const myDate& date) const {
	if (year < date.getYear()) {
		return true;
	}
	else if (year > date.getYear()) {
		return false;
	}

	if (month < date.getMonth()) {
		return true;
	}
	else if (month > date.getMonth()) {
		return false;
	}

	if (day < date.getDayOfMonth()) {
		return true;
	}
	else if (day > date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator <=(const myDate& date) const {
	if (year <= date.getYear()) {
		return true;
	}
	else if (year > date.getYear()) {
		return false;
	}

	if (month <= date.getMonth()) {
		return true;
	}
	else if (month > date.getMonth()) {
		return false;
	}

	if (day <= date.getDayOfMonth()) {
		return true;
	}
	else if (day > date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator ==(const myDate& date) const {
	if (year == date.getYear()) {
		if (month == date.getMonth()) {
			if (day == date.getDayOfMonth()) {
				return true;
			}
		}
	}

	return false;
}

bool myDate::operator !=(const myDate& date) const {
	if (year == date.getYear()) {
		if (month == date.getMonth()) {
			if (day == date.getDayOfMonth()) {
				return false;
			}
		}
	}

	return true;
}

const int MAX_SIZE = 100;
void testSimpleCase();
void testDataFromFile();
const myDate& getMinDate(const myDate dates[], int n);
const myDate& getMaxDate(const myDate dates[], int n);
void sortDates(myDate dates[], int n);
void swap(myDate &d1, myDate &d2);

int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	myDate d1, d2(99999, 12, 31), d3(2008, 2, 20);
	myDate d4, d5, d6, d7, d8, d9(d3);
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d9 << endl;
	cout << d3 - d1 << endl;
	d4 = d5 = d6 = d7 = d8 = d9;
	cout << ++d7 + 365 << " " << d7 << endl;
	cout << d7++ + 365 << " " << d7 << endl;
	cout << --d7 - 365 << " " << d7 << endl;
	cout << d7-- - 365 << " " << d7 << endl;
	cout << -365 + d7 << " " << d7 << endl;
	d4.setDate(2999, 12, 31);
	d5.setDate(2000, 1, 1);
	d6.setDate(3000, 1, 1);
	d6 += d5 - d4;
	cout << d6 << endl;
	d6 -= d5 - d4;
	cout << d6 << endl;
	cout << (d6 == d8) << " " << (d6 != d8) << endl;
	cout << (d7 == d8) << " " << (d7 != d8) << endl;
	cout << (d6 >= d8) << " " << (d6 > d8) << endl;
	cout << (d6 <= d8) << " " << (d6 < d8) << endl;
	cout << (d7 >= d8) << " " << (d7 > d8) << endl;
	cout << (d7 <= d8) << " " << (d7 < d8) << endl;
}
void testDataFromFile()
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
		int j;
		int numData;
		myDate dates[MAX_SIZE], minDate, maxDate;
		inStream >> numData;
		for (j = 0; j<numData; j++)
			inStream >> dates[j];
		minDate = getMinDate(dates, numData);
		maxDate = getMaxDate(dates, numData);
		cout << minDate << " " << maxDate << " " << maxDate - minDate << endl;
		sortDates(dates, numData);
		for (j = 0; j<numData; j++)
			cout << dates[j] << " ";
		cout << endl;
	}
	inStream.close();
}

const myDate& getMinDate(const myDate dates[], int n)
{
	int min = 0;
	for (int i = 1; i<n; i++)
	{
		if (dates[min] > dates[i])
			min = i;
	}
	return dates[min];
}

const myDate& getMaxDate(const myDate dates[], int n)
{
	int max = 0;
	for (int i = 1; i<n; i++)
	{
		if (dates[max] < dates[i])
			max = i;
	}
	return dates[max];
}

void sortDates(myDate dates[], int n)
{
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if (dates[j] > dates[j + 1])
				swap(dates[j], dates[j + 1]);
}

void swap(myDate &d1, myDate &d2)
{
	myDate tmp;
	tmp = d1;
	d1 = d2;
	d2 = tmp;
}
