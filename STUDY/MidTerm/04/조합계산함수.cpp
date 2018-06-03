#include <iostream>
using namespace std;

int combination(int n, int r);
int factorial(int n);

int main(int argc, char const *argv[]) {
  int a = 10;
  int b = 3;

  std::cout << combination(a, b) << '\n';
  return 0;
}

int combination(int n, int r){
  return (factorial(n) / (factorial(r) * factorial(n - r)));
}
int factorial(int n){
  long result = 1;
  for (size_t i = 1; i <= n; i++) {
    result = result * i;
  }
  return result;
}
