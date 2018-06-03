#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int MONTHS = 12;
  double m_salary, y_salary;

  m_salary = 100;
  y_salary = MONTHS * m_salary;
  std::cout << y_salary << '\n';
  return 0;
}
