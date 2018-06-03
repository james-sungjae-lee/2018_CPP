#include <iostream>
using namespace std;

class Car{
public:
  const int MAX_SPEED;
  const int MIN_SPEED;
  string &alias;
  Car(string s):MAX_SPEED(500), MIN_SPEED(100), alias(s){
  }
};

int main(int argc, char const *argv[]) {
  Car c("ABC");
  std::cout << c.MAX_SPEED << '\n';
  std::cout << c.MIN_SPEED << '\n';
  std::cout << c.alias << '\n';
  return 0;
}
