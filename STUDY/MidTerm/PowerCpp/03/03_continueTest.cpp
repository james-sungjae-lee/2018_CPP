#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 0, sum = 0;
  while (i < 100) {
    if (i % 2 == 1) {
      i ++ ;
      continue;
    }
    sum += i;
    i++;
  }
  std::cout << sum << '\n';
  return 0;
}
