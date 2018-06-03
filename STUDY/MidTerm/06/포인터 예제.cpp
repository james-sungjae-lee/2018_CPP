#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 3000;
  int *p = &i;

  std::cout << &i << '\n';
  std::cout << p << '\n';

  std::cout << i << '\n';
  std::cout << *p << '\n';
  return 0;
}
