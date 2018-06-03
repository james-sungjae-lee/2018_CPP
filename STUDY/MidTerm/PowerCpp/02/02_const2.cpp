#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int MONTH = 12;
  double m_sal, y_sal;

  std::cout << "월급 : ";
  std::cin >> m_sal;

  y_sal = MONTH * m_sal;
  std::cout << "연봉은 " << y_sal << "원 입니다."<< '\n';
  return 0;
}
