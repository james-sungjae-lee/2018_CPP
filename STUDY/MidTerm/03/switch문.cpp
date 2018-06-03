#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int number;
  number = 2;

  switch (number) {
    case 0:
      std::cout << "A" << '\n';
      break;
    case 2:
      std::cout << "B" << '\n';
    default:
      std::cout << "DEFAULT" << '\n';
      break;
  }
  return 0;
}
