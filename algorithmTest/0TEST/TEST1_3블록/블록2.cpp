#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int maxBlock(int a);

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

  for (size_t i = 1; i < a+1; i++) {
    if (a%i == 0) {
      if (i*i == a) {
        count++;
        count2--;
      }
      count2++;
    }
  }
  std::cout << count + count2/2 << '\n';

  return 0;
}
