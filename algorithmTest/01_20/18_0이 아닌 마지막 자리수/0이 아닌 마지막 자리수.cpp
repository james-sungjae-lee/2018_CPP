#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;

int lastNumber();

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     lastNumber();
   }

  inStream.close();
  return 0;
}

int lastNumber(){
  int caseNumber;
  int data;
  inStream >> caseNumber;
  int twoCnt = 0;
  int fiveCnt = 0;
  int tenCnt = 0;
  int times = 1;

  for (size_t i = 0; i < caseNumber; i++) {
    inStream >> data;
    while (data % 2 == 0 || data % 5 == 0) {
      if (data % 2 == 0) {
        twoCnt ++;
        data /= 2;
      }
      if (data % 5 == 0) {
        fiveCnt ++;
        data /= 5;
      }
    }
    data %= 10;
    times *= data;
    times %= 10;
  }

  while (twoCnt > 0 && fiveCnt > 0) {
    tenCnt ++;
    twoCnt --;
    fiveCnt --;
  }
  for (size_t i = 0; i < twoCnt; i++) {
    times *= 2;
    times %= 10;
  }
  for (size_t i = 0; i < fiveCnt; i++) {
    times *= 5;
    times %= 10;
  }
  std::cout << times << " " << tenCnt << '\n';
  return 0;
}
