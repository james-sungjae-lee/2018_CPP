#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int k;
  std::cin >> k;

  if (k != 0) {
    std::cout << "A" << '\n';
  }else if(k > 3){
    std::cout << "B" << '\n';
  }else{
    std::cout << "C" << '\n';
  }

  // k 가 5, 0, -1 이면 각각 A / C / A 를 출력한다.
  return 0;
}
