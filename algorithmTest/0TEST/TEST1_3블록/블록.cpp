#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int maxBlock(int a);
int arr[300];
int arr2[300];

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  int k;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> k;
     maxBlock(k);
   }
  inStream.close();
  return 0;
}

int maxBlock(int a){
  int count = 0;
  int count2 = 0;
  // 몇 개의 곱으로 나타낼 수 있는가?
  // 6 = 1 x 6 / 2 x 3 / 3 x 2 / 6 x 1
  // 9 = 1 x 9 / 3 x 3
  // 24 = 1 x 24 / 2 x 12 / 3 8 / 4 6 /
  for (size_t i = 1; i < a + 1; i++) {
    arr[i-1] = a % i;
    if (arr[i-1] == 0) {
      arr2[i-1] = i;
    }
  }
  std::cout << '\n';
  for (size_t i = 0; i < a ; i++) {
    if (arr2[i] != 0) {
      std::cout << arr2[i] << " ";

      if (arr2[i] * arr2[i] == a) {
        count++;
        count2--;
      }
      count2++;
    }
  }
  // std::cout << count + (count2 / 2) ;
  return 0;
}
