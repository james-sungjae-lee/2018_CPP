#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[]) {
  short s_money = SHRT_MAX;
  unsigned short u_money = USHRT_MAX;

  s_money = s_money + 1;
  std::cout << "s_money is : " << s_money << '\n';
  std::cout << "// 32767 -> -32768" << '\n';
  std::cout  << '\n';

  u_money = u_money + 1;
  std::cout << "u_money is : " << u_money << '\n';
  std::cout << "// 65535 -> 0" << '\n';


  return 0;
}
