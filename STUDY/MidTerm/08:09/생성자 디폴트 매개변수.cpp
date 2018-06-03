#include <iostream>
using namespace std;

class Car{
private:
  int speed;
  int gear;
  string color;
public:
  Car(int s = 10, int g = 20, string c = "blue"){
    speed = s;
    gear = g;
    color = c;
  }
  void printInfo();
};

void Car::printInfo(){
  std::cout << speed << " "<< gear << " " << color << '\n';
}

int main(int argc, char const *argv[]) {
  Car c1(0, 1, "red");
  Car c2;
  c1.printInfo();
  c2.printInfo();
  return 0;
}
