#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char letter;
  while (1) {
    std::cout << "소문자를 입력하시오 : " ;
    std::cin >> letter;

    if (letter == 'Q') {
      break;
    }
    if (letter < 'a' || letter > 'z') {
      continue;
    }

    letter -= 32;
    std::cout << letter << '\n';
  }
  return 0;
}
