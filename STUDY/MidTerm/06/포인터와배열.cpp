#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int a[] = {10, 20, 30, 40, 50};
  int b[] = {10, 20, 30, 40, 50};

  std::cout << &a[0] << '\n';
  std::cout << &a << '\n';
  std::cout << a << '\n';
  std::cout << &a[1] << '\n';

  std::cout << *a << '\n';
  std::cout << *&a[1] << '\n';
  std::cout << *(a+2) << '\n';

  int *p = a;
  std::cout << p[0] << '\n';
  return 0;
}
