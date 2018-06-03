#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  num = 3;
  switch (num) {
    case 1: std::cout << "1" << '\n';
    case 2: std::cout << "2" << '\n';
    case 3: std::cout << "3" << '\n';
    case 4: std::cout << "4" << '\n';
    break;
  }
  return 0;
}
