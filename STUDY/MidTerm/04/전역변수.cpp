#include <iostream>
using namespace std;
int x = 123;
void sub1() {
  std::cout << x << '\n';
}
void sub2() {
  std::cout << x << '\n';
}

int main(int argc, char const *argv[]) {
  sub1();
  sub2();
  return 0;
}
