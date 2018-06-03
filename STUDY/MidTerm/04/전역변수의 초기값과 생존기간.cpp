#include <iostream>
using namespace std;
int counter;

void set_counter(int i) {
  counter = i;
}

int main(int argc, char const *argv[]) {
  std::cout << counter << '\n';

  counter = 100;

  std::cout << counter << '\n';

  set_counter(20);
  std::cout << counter << '\n';
  return 0;
}
