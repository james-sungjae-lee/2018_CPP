#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  int i = 1;
  std::cout << "출력하려는 단은? : " << '\n';
  std::cin >> n;

  while (i <= 9) {
    std::cout << n << " * " << i << " = " << n*i << '\n';
    i++;
  }
  return 0;
}
