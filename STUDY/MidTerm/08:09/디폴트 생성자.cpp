#include <iostream>
#include <cstring>
using namespace std;

class Car{
public:
  int speed;
  int gear;
  string color;
public:
  Car(){
    std::cout << "디폴트 생성자 호출" << '\n';
    speed = 0;
    gear = 1;
    color = "white";
  }
};

int main(int argc, char const *argv[]) {
  Car c1;
  std::cout << '\n';
  std::cout << c1.color << '\n';
  return 0;
}
