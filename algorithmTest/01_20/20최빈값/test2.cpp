#include <iostream>
#include <cstdlib>

using namespace std;

#define N 100

void mode(double x[], int n);

int main(int argc, char const *argv[]) {
  double x[N] = {1, -1, 3, 5, 1, 3, 1, -1, 9, 2, -1, 9, 9};
  int n = 13;
  mode(x, n);
  return 0;
}

void mode(double x[], int n){
  int y[N] = {0};
  int cnt, max = 0, no_mode = 0, mode_cnt = 0;
  double num;

  for (size_t i = 0; i < n; i++) {
    cnt = 0;
    num = x[i];
    for (size_t j = i; j < n; j++) {
      if (num == x[j]) {
        cnt ++;
      }
    }
    y[i] = cnt;
    if (cnt >= 1) {
      no_mode++;
    }
  }
  if (no_mode == 0) {
    std::cout << "no mode!" << '\n';
    return;
  }
  for (size_t i = 0; i < n; i++) {
    if (y[i] > max) {
      max = y[i];
    }
  }
  for (size_t i = 0; i < n; i++) {
    if (max == y[i]) {
      mode_cnt++;
    }
  }
  std::cout << "This data set has "<< mode_cnt << " mode(s)" << '\n';
  for (size_t i = 0; i < n; i++) {
    if (max == y[i]) {
      std::cout << "The value "<< x[i] << " appeared " << y[i] << " time in the data" << '\n';
    }
  }
return;
}
