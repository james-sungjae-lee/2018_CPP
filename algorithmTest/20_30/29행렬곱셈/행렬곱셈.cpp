#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream inStream;
void mulMatrix(int numCol, int numRow, int secondRow);

int main(int argc, char const *argv[]) {
  int numTestCases, numCol, numRow, secondRow;
  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;
   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> numCol >> numRow >> secondRow;
     mulMatrix(numCol, numRow, secondRow);
   }

  inStream.close();
  return 0;
}

void mulMatrix(int numCol, int numRow, int secondRow) {
  int firstMatrix[numCol][numRow];
  int secondMatrix[numRow][secondRow];
  for (size_t i = 0; i < numCol; i++) {
    for (size_t j = 0; j < numRow; j++) {
      inStream >> firstMatrix[i][j];
    }
  }
  for (size_t i = 0; i < numRow; i++) {
    for (size_t j = 0; j < secondRow; j++) {
      inStream >> secondMatrix[i][j];
    }
  }
      int temp;
      int i,j,k;
      for ( i = 0; i < numCol; i++) {
        for ( j = 0; j < secondRow; j++) {
          temp = 0;
          for (k = 0; k < numRow; k++) {
            temp += firstMatrix[i][k] * secondMatrix[k][j];
          }
          std::cout << temp << ' ';
        }
        std::cout << '\n';
      }
}
