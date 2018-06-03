#include <iostream>
using namespace std;

class Car{
  int speed;
  int gear;
  char *pcolor;

public:
  void init(char *color);
  void start();
  void stop(Car);
  int getSpeed();
  void setSpeed(int speed);
  string color;

};

int main(int argc, char const *argv[]) {
  Car car;
  car.init("red");
  car.start();
  car.setSpeed(60);
  car.stop(car);
  car.color = "RED";
  return 0;
}
