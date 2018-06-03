#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int RATE = 5000;

  int pay;
  int hours;

  hours = 100;

  if (hours > 8) {
    pay = RATE * 8 + (int)(1.5*RATE*(hours - 8));
  }else{
    pay = RATE*hours;
  }
  std::cout << pay << '\n';
  return 0;
}
