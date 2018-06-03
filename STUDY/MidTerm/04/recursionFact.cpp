#include <iostream>
using namespace std;

int factorial(int n){
  if (n <= 1) {
    return 1;
  }else{
    return n * factorial(n - 1);
  }
}

int factorial_iter(int n){
  int value = 1;
  for (size_t i = 1; i <= n; i++) {
    value = value * i;
  }
  return value;
}

int main(int argc, char const *argv[]) {
  std::cout << factorial(10) << '\n';
  std::cout << factorial_iter(10) << '\n';
  return 0;
}
