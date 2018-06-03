#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  int numSumCases;
  int arr[30];
  int max, min;

   inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }
inStream >> numTestCases;

for (size_t i = 0; i < numTestCases; i++) {
  inStream >> numSumCases;
  for (size_t i = 0; i < numSumCases; i++) {
    inStream >> arr[i];
  }
  max = arr[0];
  min = arr[0];
  for (size_t i = 1; i < numSumCases; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  std::cout << max + min << '\n';
}
  inStream.close();
  return 0;
}
