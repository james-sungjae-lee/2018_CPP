#include <iostream>
#include <string>
using namespace std;

class Date{
// public:
  void printDate(){
    std::cout << year << " " << month << " " << day << '\n';
  }
  int getDay(){
    return day;
  }
  int year;
  string month;
  int day;
};

class Car{
private:
  int speed;
  int gear;
  string color;

public:
  int getSpeed(){
    return speed;
  }
  void setSpeed(int s){
    speed = s;
  }
  int getGear(){
    return gear;
  }
  void setGear(int g){
    gear = g;
  }
  string getColor(){
    return color;
  }
  void setColor(string c){
    color = c;
  }
  void honk();
};

void Car::honk(){
  std::cout << "빵빵!" << '\n';
}

int main(int argc, char const *argv[]) {
  Car mycar;
  mycar.setSpeed(80);
  mycar.honk();
  std::cout << "현재 속도는 " << mycar.getSpeed() << "km/h 입니다." << '\n';
  return 0;
}




















//
