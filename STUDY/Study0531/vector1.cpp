#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<double> scores(10);

  for (size_t i = 0; i < scores.size(); i++) {
    std::cout << "성적 입력 : " << ' ';
    std::cin >> scores[i];
  }

  double heighest = scores[0];
  for (size_t i = 0; i < scores.size(); i++) {
    if (scores[i] > heighest) {
      heighest = scores[i];
    }
  }
  std::cout << "최고 성적은 " << heighest << '\n';
  return 0;
}
