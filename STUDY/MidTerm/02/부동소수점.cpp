#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {

  float x = 1e39;
  std::cout << x << '\n';

  float y = 1.23456e-40;
  std::cout << y << '\n';

  float z = 1.23456e-46;
  std::cout << z << '\n';

  double k;
  k = (1.0e20 + 50) - 1.0e20;
  std::cout << "k : "<< k << '\n';

  cout.setf(ios_base::fixed);
  float fvalue = 1234567890.12345678901234567890;
  double dvalue = 1234567890.12345678901234567890;

  std::cout << "float : "<< fvalue << '\n';
  std::cout << "double : " << dvalue << '\n';


  return 0;
}
