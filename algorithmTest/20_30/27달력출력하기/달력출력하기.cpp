#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void printCalendar(int year, int month);

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;
   int year, month;
   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> year >> month;
     printCalendar(year, month);
   }
  inStream.close();
  return 0;
}

void printCalendar(int year, int month){
  std::cout << year << " " << month << '\n';

  int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int days = 0;
  int firstDay = 0;
  int cnt = 0;
  int temp = year - 1;

  days = temp*365 + (temp/4) - (temp/100) + (temp/400);
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    day[1] = 29;
  }else{
    day[1] = 28;
  }
  for (size_t i = 0; i < month - 1; i++) {
    days += day[i];
  }
  days -= 1;
  firstDay = days % 7;

  // 첫 번째 요일과 전체 날 수의 계산 완료

  for (size_t i = 0; i <= firstDay; i++) {
    if (firstDay != 6) {
      std::cout << 0 << ' ';
      cnt++;
    }
  }
  for (size_t i = 0; i <= day[month - 1]; i++) {
    if (cnt >= 7) {
      std::cout << '\n';
      cnt = 0;
    }
    std::cout << i << ' ';
    cnt++;
  }
  for (size_t i = 0; i < 7-cnt; i++) {
    std::cout << 0 << ' ';
  }
  std::cout << '\n';
  // 일 - 월 - 화 - 수 - 목 - 금 - 토 형식
  // 2. 해당 월의 1일에 대해 알아본다.
  // 3. 해당 월의 1일이 해당되는 요일을 찾아낸다.
  // 4. 그 요일부터 출력을 시작하여, 해당 월이 가지는 일수만큼 출력한다.
}
