

// var1, var2 라는 이름의 변수를 정수형으로 선언하고 97 과 49 라는 값을 이 변수에 치환하고,
// 두 수를 더한 값을 var1 에 새로 넣고 
// 그 값을 출력하는
// cout << “var1 = “ << var1 << “\n” ;
// C++ 프로그램을 작성하여 
// var12.cpp 라는 화일로 저장한 후 
// g++ 로 컴파일하고 수행하는 것을 확인하라.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int var1 = 97, var2 = 49;
  var1 = var1 + var2;
  std::cout << "var1 = " << var1 << '\n';
  return 0;
}
