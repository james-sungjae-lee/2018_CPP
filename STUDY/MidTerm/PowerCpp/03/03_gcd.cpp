#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x, y, t, r;
  std::cin >> x;
  std::cin >> y;
  if (x < y) {
    t = y;
    y = x;
    x = t;
  }
  // 이제 큰 수가 x, 작은 수가 y이다.

  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  // y 가 0이 아닐 때, 반복한다.

  std::cout << x << '\n';

  return 0;
}
