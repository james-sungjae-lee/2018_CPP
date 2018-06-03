#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 20;
  do {
    std::cout << i << '\n';
    i++;
  } while(i < 10);
  std::cout << i << '\n';
  return 0;
}
