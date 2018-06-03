#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<double> scores;

  while (1) {
    double value = 0.0;
    std::cout << "성적을 입력하세요 : " << ' ';
    std::cin >> value;
    if (value < 0.0) {
      break;
    }
    scores.push_back(value);
  }

  double highest = scores[0];
  for (size_t i = 0; i < scores.size(); i++) {
    if (scores[i] > highest) {
      highest = scores[i];
    }
  }
  std::cout << "최고 성적은 : " << highest << '\n';
  return 0;
}
