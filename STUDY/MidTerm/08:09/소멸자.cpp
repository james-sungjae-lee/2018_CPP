#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
  int speed;
  int gear;
  string color;
public:
  Car(int s, int g, string c){
    speed = s;
    gear = g;
    color = c;
  }
  Car(int s, int g, char *c){
    speed = s;
    gear = g;
    color = new char[strlen(c) + 1];
  }
  Car(){
    speed = 10;
    gear = 2;
    color = "white";
  }
  ~Car(){
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
