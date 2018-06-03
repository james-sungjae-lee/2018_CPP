#include <iostream>
using namespace std;
void sub(void);

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 5; i++) {
    sub();
  }
  return 0;
}
void sub(void) {
  int auto_count = 0;
  static int static_count = 0;

  auto_count++;
  static_count++;
  std::cout << auto_count << ' ';
  std::cout << static_count << ' ';
  std::cout << '\n';
}
