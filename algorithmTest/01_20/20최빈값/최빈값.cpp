#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;
int arr[100] = {0};
int arr2[100] = {0};
int arr3[100] = {0};

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
  int nNumber, t;
  inStream >> nNumber;
  for (size_t i = 0; i < nNumber; i++) {
    inStream >> t;
    arr[i] = t;
    std::cout << arr[i] << " ";
  }
  int max = 1;
  std::cout << '\n';
  for (size_t j = 0; j < nNumber; j++) {
    int count = 0;
    for (size_t i = 0; i < nNumber; i++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
    arr2[j] = count;
    std::cout << arr2[j] << " ";
    if (max < arr2[j]) {
      max = arr2[j];
    }
  }
  std::cout << '\n';
  for (size_t i = 0; i < nNumber; i++) {
    if (arr2[i] < max) {
      arr2[i] = 0;
      arr[i] = 0;
    }
  }
  for (size_t i = 0; i < nNumber; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';
  for (size_t i = 0; i < nNumber; i++) {
    std::cout << arr2[i] << " ";
  }

// 배열 내의 서로 다른 숫자 오름차순으로 저장하기
// 맥스의 개수 / 위에서 저장한 숫자의 개수 = 최빈값의 개수
// 최빈값의 개수 + 최빈값의 빈도 + 서로 다른 숫자들













  return 0;
}
