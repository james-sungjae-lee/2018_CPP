#include <iostream>
#include <string>
using namespace std;

class Car{
  int speed;
  int gear;
  string color;
public:
  Car(int s=0, int g=1, string c="white") : speed(s), gear(g), color(c) {
  }
  void display();
};

void Car::display(){
  std::cout << speed << '\n';
  std::cout << gear << '\n';
  std::cout << color << '\n';
}

void swapObjects(Car c1, Car c2){
  Car temp;
  temp = c1;
  c1 = c2;
  c2 = temp;
  c1.display();
  c2.display();
}

Car buyCar(){
  Car temp(0, 1, "metal");
  return temp;
}

void swapObjects(Car* p1, Car* p2){
  Car temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  p1->display();
  p2->display();
}

int main(int argc, char const *argv[]) {
  // Car mine(0, 1, "white");
  // Car your(0, 1, "red");
  // swapObjects(mine, your);
  // mine.display();
  // your.display();

  // Car c1;
  // c1.display();
  // c1 = buyCar();
  // c1.display();

  Car mine(0, 1, "white");
  Car yours(0, 1, "red");
  swapObjects(&mine, &yours);
  mine.display();
  yours.display();

  return 0;
}
