#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  double v;

  while (1) {
    v = 4.0;
    std::cout << sqrt(v) << '\n';
    v = -1;
    if (v < 0.0) {
      std::cout << "반복 종료" << '\n';
      break;
    }
  }
  return 0;
}
