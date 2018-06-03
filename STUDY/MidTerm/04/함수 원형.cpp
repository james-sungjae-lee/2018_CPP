#include <iostream>
using namespace std;

int compute_sum(int n);
int main(int argc, char const *argv[]) {
  int n, sum;
  n = 10;
  sum = compute_sum(n);
  std::cout << sum << '\n';
  return 0;
}

int compute_sum(int n){
  int result = 0;
  for (size_t i = 1; i <= n; i++) {
    result += i;
  }
  return result;
}
