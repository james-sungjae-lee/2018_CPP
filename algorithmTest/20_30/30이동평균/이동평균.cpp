#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream inStream;

void movingAvg();

int main(int argc, char const *argv[]) {
  int numTestCases;
  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;
   for (size_t i = 0; i < numTestCases; i++) {
     movingAvg();
   }

  inStream.close();
  return 0;
}

void movingAvg() {
  int numOfNum, week, numOfResult;
  inStream >> numOfNum;
  int num[numOfNum];
  for (size_t i = 0; i < numOfNum; i++) {
    inStream >> num[i];
  }
  inStream >> week;

  numOfResult = numOfNum - week + 1;
  std::cout << numOfResult << ' ';

  int result;
  for (size_t i = 0; i < numOfResult; i++) {
    result = 0;
    for (size_t j = i; j < week + i; j++) {
      result += num[j];
    }
    result /= week;
    std::cout << result << ' ';
  }
  std::cout << '\n';

}
