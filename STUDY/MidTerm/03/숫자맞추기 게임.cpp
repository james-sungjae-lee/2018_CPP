#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int answer = 59;
  int guess;
  int tries = 0;

  do{
    std::cout << "정답은? " << '\n';
    std::cin >> guess;
    tries ++;
    if (guess > answer) {
      std::cout << "high" << '\n';
    }
    if (guess < answer) {
      std::cout << "low" << '\n';
    }
  }while(guess != answer);

  std::cout << "성공!" << '\n';
  return 0;
}
