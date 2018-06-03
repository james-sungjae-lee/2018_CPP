#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int answer = 38;
  int guess;
  int tries = 0;

  do {
    std::cin >> guess;
    if (guess < answer) {
      std::cout << "더 크게!" << '\n';
      tries ++;
    }
    if (guess > answer) {
      std::cout << "더 작게.." << '\n';
      tries ++;
    }
  } while(guess != answer);

  std::cout << "정답! " << guess << "을 " << tries << "번 만에 맞췄습니다." << '\n';
}
