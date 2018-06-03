// 정수형 변수 var 를 선언하고 97을 치환
//
// 문자 포인터형 변수 ptr을 선언하고, 포인터형 변수를 사용하여 var 에 저장된 값을 숫자가 아닌 “문자” 로 출력한다.
//
// 위의 코드를 컴파일하고 수행한다.
//
// 검사받을 화면은 cat 명령으로 source code를 보이고, 그 다음 compile 하는 명령어, 컴파일된 코드를 수행하는 것을 보이는 상태로 검사를 받는다.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int var = 97;

  int *ptr = &var;

  char s[] = "processing!!@#$$#";

  char *ps[] = {"network", "security", "vision"};

  std::cout << *ptr << '\n';

  return 0;
}
