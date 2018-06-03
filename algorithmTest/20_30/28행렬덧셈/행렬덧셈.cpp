#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream inStream;
void sumMatrix(int numCol, int numRow);

int main(int argc, char const *argv[]) {
  int numTestCases, numCol, numRow;
  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;
   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> numCol >> numRow;
     sumMatrix(numCol, numRow);
   }

  inStream.close();
  return 0;
}

void sumMatrix(int numCol, int numRow) {
  int firstMatrix[numCol][numRow];
  int secondMatrix[numCol][numRow];
  int resultMatrix[numCol][numRow];
  for (size_t i = 0; i < numCol; i++) {
    for (size_t j = 0; j < numRow; j++) {
      inStream >> firstMatrix[i][j];
    }
  }
  for (size_t i = 0; i < numCol; i++) {
    for (size_t j = 0; j < numRow; j++) {
      inStream >> secondMatrix[i][j];
    }
  }
  for (size_t i = 0; i < numCol; i++) {
    for (size_t j = 0; j < numRow; j++) {
      resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
      std::cout << resultMatrix[i][j] << " ";
    }
    std::cout << '\n';
  }
}
