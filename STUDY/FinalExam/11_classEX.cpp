#include <iostream>
#include <string>
using namespace std;

class Car{
  int speed;
  int gear;
  string color;
public:
  Car (int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c){
  }
  void display();
};

void Car::display(){
  std::cout << speed << '\n';
  std::cout << gear << '\n';
  std::cout << color << '\n';
}

int main(int argc, char const *argv[]) {
  Car myCar;
  myCar.display();

  Car* pCar = &myCar;
  pCar -> display();

  pCar = new Car(0, 1, "blue");
  pCar -> display();
  
  return 0;
}
