#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int *pi;
  pi = new int;
  *pi = 100;
  std::cout << pi << '\n';
  std::cout << *pi << '\n';
  delete pi;
  return 0;
}
