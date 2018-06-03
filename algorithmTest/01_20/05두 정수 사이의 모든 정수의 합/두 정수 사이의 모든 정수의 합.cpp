#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int sumBetween(int a, int b);

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
     int a, b;
     inStream >> a;
     inStream >> b;
     sumBetween(a, b);
   }

  inStream.close();
  return 0;
}

int sumBetween(int a, int b){
  int sum = 0;
  for (size_t i = a; i < b + 1; i++) {
    sum = sum + a;
    a++;
  }
  std::cout << sum << '\n';
  return 0;
}
