#include <iostream>
using namespace std;

void sub() {
  int *pi = new int;
  *pi = 67;
  pi = new int;
  *pi = 99;
}

void sub2() {
  int *pi = new int;
  *pi = 67;
  std::cout << *pi << '\n';
  delete pi;

  pi = new int;
  *pi = 99;
  std::cout << *pi << '\n';
  delete pi;
}

int main(int argc, char const *argv[]) {
  sub2();
  return 0;
}
