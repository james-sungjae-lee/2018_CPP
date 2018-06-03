#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 10;
  char c = 69;
  double f = 12.3;

  char *pc = &c;
  int *pi = &i;
  double *pf = &f;

  std::cout << *pc << '\n';
  std::cout << *pi << '\n';
  std::cout << *pf << '\n';

  std::cout << (void *)pc << '\n';
  std::cout << pi << '\n';
  std::cout << pf << '\n';

}
