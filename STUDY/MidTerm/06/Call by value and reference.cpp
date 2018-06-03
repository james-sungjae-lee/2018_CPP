#include <iostream>
using namespace std;
void swap1(int x, int y);
void swap2(int *px, int *py);
void swap3(int &x, int &y);

int main(int argc, char const *argv[]) {
  int a = 100;
  int b= 200;

  std::cout << a << " " << b << '\n';

  swap1(a, b);

  std::cout << a << " " << b << '\n';

  swap2(&a, &b);

  std::cout << a << " " << b << '\n';

  swap3(a, b);

  std::cout << a << " " << b << '\n';
  return 0;
}

void swap1(int x, int y){
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void swap2(int *px, int *py) {
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}

void swap3(int &x, int &y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}
