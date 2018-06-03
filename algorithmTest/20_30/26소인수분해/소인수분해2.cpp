#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Counts{
public:
  int num;
  int cnt;
};
Counts primeNumbers[10000];

void calc(int inputNumber);
int primeCount; // input을 나누어서 ??
int divideNum; // input을 나누어주기 위한 숫자.

int main(int argc, char const *argv[]) {
  ifstream inStream;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "open fail" << '\n';
    exit(1);
  }

  int numTestCases;
  inStream >> numTestCases;

  int inputNumber;
  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> inputNumber;
    calc(inputNumber);
  }

  inStream.close();
  return 0;
}

void calc(int inputNumber) {
  primeCount = 0;
  divideNum = 2;

  while (1) {
    if (inputNumber % divideNum == 0) {
      primeNumbers[primeCount].num = divideNum;

      while (1) {
        if (inputNumber % divideNum != 0) {
          primeCount++;
          break;
        }else{
          primeNumbers[primeCount].cnt++;
          inputNumber = inputNumber / divideNum;
        }
      }
      if (inputNumber == 1) {
        break;
      }
    }
    divideNum++;
  }

  std::cout << primeCount;
  for (size_t i = 0; i < primeCount; i++) {
    std::cout << " " << primeNumbers[i].num << " " << primeNumbers[i].cnt;
    primeNumbers[i].num = 0;
    primeNumbers[i].cnt = 0;
  }
  std::cout << '\n';
}
