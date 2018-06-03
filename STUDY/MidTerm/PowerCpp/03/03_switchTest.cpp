#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  std::cout << "숫자를 입력 : ";
  std::cin >> num;

  switch (num) {
    case 0:
      std::cout << "없음" << '\n';
      break;
    case 1:
      std::cout << "1" << '\n';
      break;
    case 2:
      std::cout << "2" << '\n';
      break;
    default:
      std::cout << "디폴트" << '\n';
      break;
  }
  return 0;
}
