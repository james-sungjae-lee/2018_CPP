#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  if (n >= 100) {
    std::cout << "large" << '\n';
  }else{
    std::cout << "small" << '\n';
  }
  return 0;
}
