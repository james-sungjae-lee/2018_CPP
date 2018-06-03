#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int factorialSum(int n){

  if (n == 0) {
    return 0;
  }
  return n + factorialSum(n-1);
}

int triagleNumber(int n){

  int temp = 1;

  int arr[n + 1][n + 1];
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      arr[i][j] = temp;
      temp++;
    }
    temp = temp - (i + 1);
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < i + 1; j++) {
      std::cout << arr[j][i] << " ";
    }
    std::cout << '\n';
  }

//
// [0]
// [1] [3]
// [2] [4] [5]
//
// [0]
// [1] [6 = 1 + 5]
// [2] [7 = 2 + 5] [11 = 7 + 4]
// [3] [8 = 3 + 5] [12 = 8 + 4] [15 = 12 + 3]
// [4] [9] [13] [16] [18]
// [5] [10] [14] [17] [19] [20]

// 3 이 들어왔다.
// 3줄 출력한다.
// 1번째 줄은 1개 출력한다.
// 2번째 줄은 2개 출력한다.
// 3번째 줄은 3개 출력한다.
  return 0;
}



int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     int k;
     inStream >> k;
     triagleNumber(k);
   }

  inStream.close();
  return 0;
}
