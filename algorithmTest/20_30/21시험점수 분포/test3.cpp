#include <iostream>
#include <fstream>
#include <cstdlib>
#define N 100

using namespace std;
ifstream inStream;

int arr[N] = {0};
int arr2[N] = {0};
int countValue();

int main(int argc, char const *argv[]) {
  int numTestCases;
  inStream.open("input.txt");

  if (inStream.fail()) {
    std::cerr << "Input file opening failed" << '\n';
    exit(1);
  }
  inStream >> numTestCases;
  for (size_t i = 0; i < numTestCases; i++) {
    countValue();
    std::cout << '\n';
  }
  inStream.close();
  return 0;
}

int countValue(){
  int caseNum, inStreamTemp;
  inStream >> caseNum;
  for (size_t i = 0; i < caseNum; i++) {
    inStream >> inStreamTemp;
    arr[i] = inStreamTemp;
    std::cout << arr[i] << " ";
  }
  return 0;
}
