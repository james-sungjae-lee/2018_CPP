#include <iostream>
using namespace std;

int referenceF(int &a);

int main(int argc, char const *argv[]) {
  int var;
  int &ref = var;
  var = 10;
  std::cout << var << '\n';
  std::cout << ref << '\n';
  ref = 20;
  std::cout << var << '\n';
  std::cout << ref << '\n';

  int k = 10000;

  std::cout << referenceF(k) << '\n';
  return 0;
}

int referenceF(int &a){
  return a;
}
