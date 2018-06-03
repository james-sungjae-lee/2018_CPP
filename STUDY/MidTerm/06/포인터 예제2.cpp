#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  char c = 'A';
  int i = 10000;
  double d = 6.78;

  char *pc = &c;
  int *pi = &i;
  double *pd = &d;

  (*pc) ++;
  *pi = *pi + 1;
  *pd += 1;

  std::cout << c << '\n';
  std::cout << i << '\n';
  std::cout << d << '\n';

  std::cout << *pc << '\n';
  pc++;
  std::cout << *pc << '\n';
  std::cout << c << '\n';
  return 0;
}
