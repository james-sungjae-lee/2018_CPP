#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;

int setCal();

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     setCal();
   }

  inStream.close();
  return 0;
}

int setCal(){
  int setNum;
  int a[132];
  int b[132];
  int c[132];
  int d[132];
  int e[132];

  int data;
  int cnt = 0;
  int t = 0;

  inStream >> setNum;

  for (size_t i = 0; i < 132; i++) {
    a[i] = 0;
    b[i] = 0;
    c[i] = 0;
    d[i] = 0;
    e[i] = 0;
  }

  // 집합 원소 저장하기
  for (size_t i = 0; i < setNum; i++) {
    inStream >> data;
    a[data] = 1;
  }

  inStream >> setNum;

  for (size_t i = 0; i < setNum; i++) {
    inStream >> data;
    b[data] = 1;
  }

  // 교집합 구하기
  for (size_t i = 0; i < 132; i++) {
    if (a[i] == 1 && b[i] == 1) {
      cnt = cnt + 1;
      c[t] = i;
      t ++;
    }
  }

  std::cout << cnt << " ";

  for (size_t i = 0; i < cnt; i++) {
    std::cout << c[i] << " ";
  }
  std::cout << '\n';

  // 합집합 구하기

  t = 0;
  cnt = 0;

  for (size_t i = 0; i < 132; i++) {
    if (a[i] == 1 || b[i] == 1) {
      cnt = cnt + 1;
      d[t] = i;
      t ++;
    }
  }
  std::cout << cnt << " ";

  for (size_t i = 0; i < cnt; i++) {
    std::cout << d[i]  << " ";
  }
  std::cout << '\n';

  // 차집합

  t = 0;
  cnt = 0;

  for (size_t i = 0; i < 132; i++) {
    if (a[i] == 1 && b[i] == 0) {
      cnt = cnt + 1;
      e[t] = i;
      t ++;
    }
  }
  std::cout << cnt << " ";

  for (size_t i = 0; i < cnt; i++) {
    std::cout << e[i] << " ";
  }
  std::cout << '\n';
  return 0;
}
