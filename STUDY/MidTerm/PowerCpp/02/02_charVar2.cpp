#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char ch = 'A';
  int code = ch;

  std::cout << ch << "의 아스키 코드 : " << code << '\n';

  ch = ch+1;
  code = ch;
  std::cout << ch << "의 아스키 코드 : " << code << '\n';
  return 0;
}
