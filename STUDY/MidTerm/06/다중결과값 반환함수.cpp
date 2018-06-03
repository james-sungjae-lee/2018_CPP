#include <iostream>
using namespace std;

int getLineParameter(int x1, int y1, int *slope, int *yintercept){
  x1 = 1;
  y1 = 2;
  (*slope) ++;
  (*yintercept) ++;
  return 0;
}

int main(int argc, char const *argv[]) {
  int a = 0;
  int b = 0;
  getLineParameter(a, b, &a, &b);
  std::cout << a << " "<< b << '\n';
  return 0;
}
