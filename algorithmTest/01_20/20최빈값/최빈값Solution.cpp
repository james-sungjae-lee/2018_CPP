#include <iostream>
#include <fstream>
#include <cstdlib>

#define N 100

using namespace std;
ifstream inStream;
int arr[N] = {0};
int arr2[N] = {0};
int queueCount = 0;

const int queueSize = 100;
int queue[queueSize];
int rear, front;


int countNumber();

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     countNumber();
     std::cout << '\n';
   }

  inStream.close();
  return 0;
}

int countNumber(){
  int nNumber, t, swapTemp;
  inStream >> nNumber;
  for (size_t i = 0; i < nNumber; i++) {
    inStream >> t;
    arr[i] = t;
  }
  for (size_t i = 0; i < nNumber - 1; i++) {
    for (size_t j = 0; j < nNumber - 1 - i; j++) {
      if (arr[j] > arr[j+1]) {
        swapTemp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = swapTemp;
      }
    }
  }

  int max = 0;
  for (size_t i = 0; i < nNumber; i++) {
    for (size_t j = 0; j < nNumber; j++) {
      if (arr[i] == arr[j]) {
        max++;
      }
    }
    arr2[i] = max;
    max = 0;
  }

  for (size_t i = 0; i < nNumber - 1; i++) {
    for (size_t j = 0; j < nNumber - 1 - i; j++) {
      if (arr2[j] < arr2[j+1]) {
        swapTemp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = swapTemp;
        swapTemp = arr2[j];
        arr2[j] = arr2[j+1];
        arr2[j+1] = swapTemp;
      }
    }
  }

  int y[N] = {0};
  int cnt, maxVal = 0, no_mode = 0, mode_cnt = 0;
  double num;

  for (size_t i = 0; i < nNumber; i++) {
    cnt = 0;
    num = arr[i];
    for (size_t j = i; j < nNumber; j++) {
      if (num == arr[j]) {
        cnt ++;
      }
    }
    y[i] = cnt;
    if (cnt >= 1) {
      no_mode++;
    }
  }
  if (no_mode == 0) {
    std::cout << "no mode!" << '\n';
  }
  for (size_t i = 0; i < nNumber; i++) {
    if (y[i] > maxVal) {
      maxVal = y[i];
    }
  }
  for (size_t i = 0; i < nNumber; i++) {
    if (maxVal == y[i]) {
      mode_cnt++;
    }
  }

  int countMaxValues = 0;

  for (size_t i = 0; i < nNumber; i++) {
    if (maxVal == y[i]) {
      countMaxValues ++;
    }
  }
  std::cout << countMaxValues << " ";

  std::cout << maxVal << " ";

  for (size_t i = 0; i < nNumber; i++) {
    if (maxVal == y[i]) {
      std::cout << arr[i] << " ";
    }
  }

  return 0;
}
