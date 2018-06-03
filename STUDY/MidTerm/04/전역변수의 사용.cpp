#include <iostream>
using namespace std;

void f(void);

int i;

int main(void) {
  for (i = 0; i < 5; i++) {
    f();
    std::cout << '\n';
  }
  return 0;
}

void f(void) {
  for (i = 0; i < 10; i++) {
    std::cout << "#" << " ";
  }
}

// i 의 사용이 전역변수로 설정되어, for문이 정상적으로 작동하지 않았음.
