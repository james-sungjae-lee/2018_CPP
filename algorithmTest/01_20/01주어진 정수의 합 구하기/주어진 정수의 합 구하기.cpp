#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  int numSumCases;
  int arr[10000];
  int sum = 0;

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
    sum += arr[i];
  }
  std::cout << sum << '\n';
  sum = 0;
}
  inStream.close();
  return 0;
}
