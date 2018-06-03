#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int timeCal(int a, int b, int c);

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  int hourA, MinA, TimeA;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> hourA;
     inStream >> MinA;
     inStream >> TimeA;
     timeCal(hourA, MinA, TimeA);
   }

  inStream.close();
  return 0;
}

int timeCal(int a, int b, int c){
  int hour = c / 60;
  int min = c % 60; 

  int returnHour = a + hour;
  int returnMin = b + min;

  if (returnMin >= 60) {
    returnHour = returnHour + 1;
  }

  returnHour = returnHour % 24;
  returnMin = returnMin % 60; // 60 으로 나누어 주었을 때,

  std::cout << returnHour << " " << returnMin << '\n';
  return 0;
}
