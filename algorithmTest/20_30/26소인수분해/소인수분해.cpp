#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

typedef struct{
  int num;
  int count;
}str;

class Variable{
public:
  int numCases;
  int inputNum;
  int num;
  int primeCount;
};

Variable vr;
str prime[1000];

void calc();

int main(int argc, char const *argv[]) {
  ifstream inStream;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> vr.numCases;

   for (size_t i = 0; i < vr.numCases; i++) {
     inStream >> vr.inputNum;
     calc();
   }

  inStream.close();
  return 0;
}

void calc() {
  vr.primeCount = 0;
  vr.num = 2;

  while (1) {
    if (vr.inputNum % vr.num == 0) {
      prime[vr.primeCount].num = vr.num;

      while (1) {
        if (vr.inputNum % vr.num != 0) {
          vr.primeCount++;
          break;
        }else{
          prime[vr.primeCount].count++;
          vr.inputNum /= vr.num;
        }
      }
      if (vr.inputNum == 1) {
        break;
      }
    }
    vr.num++;
  }

  std::cout << vr.primeCount;
  for (size_t i = 0; i < vr.primeCount; i++) {
    std::cout << " " << prime[i].num << " " << prime[i].count;
    prime[i].num = 0;
    prime[i].count = 0;
  }
  std::cout << '\n';
}
