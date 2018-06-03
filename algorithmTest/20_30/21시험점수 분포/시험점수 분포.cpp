#include <iostream>
#include <fstream>
#include <cstring>

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
  int caseNum, inStreamTemp, swapTemp;
  inStream >> caseNum;

  // instream to array
  for (size_t i = 0; i < caseNum; i++) {
    inStream >> inStreamTemp;
    arr[i] = inStreamTemp;
  }

  // sorting
  for (size_t i = 0; i < caseNum - 1; i++) {
    for (size_t j = 0; j < caseNum - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swapTemp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swapTemp;
      }
    }
  }

  // count values
  int cnt, num;
  int y[N] = {0};

  for (size_t i = 0; i < caseNum; i++) {
    cnt = 0;
    num = arr[i];
    for (size_t j = 0; j < caseNum; j++) {
      if (num == arr[j]) {
        cnt ++;
      }
    }
    y[i] = cnt;
  }

  for (size_t i = 0; i < caseNum; i++) {
    if (arr[i] != arr[i+1]) {
      std::cout << arr[i] << " " << y[i] << " ";
    }
  }
  return 0;
}
