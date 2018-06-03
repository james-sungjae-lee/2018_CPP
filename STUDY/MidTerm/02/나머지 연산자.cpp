#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int input, minute, second;
  const int SEC_PER_MINUIT = 60;
  input = 1234256;

  minute = input / SEC_PER_MINUIT;
  second = input % SEC_PER_MINUIT;

  std::cout << input << " 초는 " << minute << " 분 " << second <<" 초 입니다." << '\n';
  return 0;
}
