#include <iostream>
using namespace std;

class Date{
private:
  int year;
  int month;
  int day;
public:
  Date();
  Date(int year);
  Date(int year, int month, int day);
  void setDate(int year, int month, int day);
  void print();
};

Date::Date(){
  year = 2010;
  month = 1;
  day = 1;
}

Date::Date(int year){
  setDate(year, 1, 1);
}

Date::Date(int year, int month, int day){
  this -> month = month;
  this -> day = day;
  this -> year = year;
}

void Date::print(){
  std::cout << year << " " << month << " " << day << '\n';
}

int main(int argc, char const *argv[]) {
  Date a;
  a.print();
  return 0;
}
