#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int x = 5;
  int &ref = x;
  x = 10;
  std::cout << ref << '\n';
  std::cout << x << '\n';
  int a = 1;
  int b = 2;
  swap(a, b);
  std::cout << a << " " << b << '\n';
  return 0;
}

void swap(int& left, int& right) {
  int temp = right;
  right = left;
  left = temp;
}
