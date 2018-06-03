#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[]) {
  string id, pass;

  std::cout << "아이디와 패스워드 입력 : " << '\n';
  std::cout << "id : __________ \b\b\b\b\b\b\b\b\b\b\b" ;
  std::cin >> id;
  std::cout << "password : __________ \b\b\b\b\b\b\b\b\b\b\b" ;
  std::cin >> pass;

  std::cout << "아이디 : " << id << '\n';
  std::cout << "패스워드 : " << pass << '\n';
  return 0;
}
