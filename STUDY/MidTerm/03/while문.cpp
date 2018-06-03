#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 0;
  while (i < 5) {
    std::cout << "정수 : " << i++ << '\n';
  }
  return 0;
}
