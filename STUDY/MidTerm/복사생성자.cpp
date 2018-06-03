#include <iostream>
#include <cstring>
using namespace std;

class Car{
  int speed;
  int gear;
  string color;
public:
  Car(int s, int g, string c){
    speed = s;
    gear = g;
    color = c;
  }
  void printInfo(){
    std::cout << speed << " " << gear << " " << color << '\n';
  }
};

int main(int argc, char const *argv[]) {
  Car c1(0, 1, "yellow");
  Car c2(c1);
  c1.printInfo();
  c2.printInfo();
  return 0;
}
