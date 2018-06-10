#include <iostream>
using namespace std;

class Car{
  int s;
  int g;
  string c;
  int id;
public:
  static int numberOfCars;
  Car(int s=0, int g=1, string c="white") : s(s), g(g), c(c){
    id = ++numberOfCars;
  }
};

int Car::numberOfCars = 0;

int main(int argc, char const *argv[]) {
  Car c1;
  std::cout << Car::numberOfCars << '\n';

  Car c2;
  std::cout << c2.numberOfCars << '\n';
  return 0;
}
