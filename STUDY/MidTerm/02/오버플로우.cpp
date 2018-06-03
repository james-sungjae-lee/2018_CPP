#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {
  short s_money = SHRT_MAX;
  unsigned short u_money = USHRT_MAX;

  s_money ++;
  u_money ++;
  std::cout << s_money << '\n';
  std::cout << u_money << '\n';
  return 0;
}
