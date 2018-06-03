#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int income;
  int tax;

  income = 1000000;
  if (income <= 1000) {
    tax = (int)(0.09*income);
  }else if (income <= 4000) {
    tax = (int)(0.18*income);
  }else if (income < 8000) {
    tax = (int)(0.27*income);
  }else{
    tax = (int)(0.36 * income);
  }
  std::cout << tax  << '\n';
  return 0;
}
