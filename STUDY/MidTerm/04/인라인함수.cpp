#include <iostream>
using namespace std;

inline double square(double i){
  return i*i;
}

int main(){
  double result;
  result = square(2.0);
  std::cout << result << '\n';
  result = square(3.0);
  std::cout << result << '\n';
}
