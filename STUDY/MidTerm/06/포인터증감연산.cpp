#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char *pc;
  int *pi;
  double *pd;

  pc = (char *)10000;
  pi = (int *)10000;
  pd = (double *)10000;
  std::cout << (void *)pc << " " << pi << " " << pd << '\n';

  pc++;
  pi++;
  pd++;
  std::cout << (void *)pc << " " << pi << " " << pd << '\n';

  return 0;
}
