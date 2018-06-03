#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void calDate(int yearNum, int monthNum, int dayNum);
int calYear(int Y);

int yunMonth[13][2] = {{1, 31},{2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
                      {7, 31}, {8, 31}, {9, 30}, {10, 31},{11, 30}, {12, 31}};

int pyungMonth[13][2] = {{1, 31},{2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
                      {7, 31}, {8, 31}, {9, 30}, {10, 31},{11, 30}, {12, 31}};

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   int yearNum, monthNum, dayNum;
   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> yearNum >> monthNum >> dayNum;
     calDate(yearNum, monthNum, dayNum);
   }

  inStream.close();
  return 0;
}

void calDate(int yearNum, int monthNum, int dayNum){
  int firstYear = 1582;
  int numOfYun = 0;
  int numOfPyung = 0;
  while (firstYear < yearNum) {
    if (calYear(firstYear) == 1) {
      numOfYun++;
    }else{
      numOfPyung++;
    }
    firstYear++;
  }

  int days = numOfYun*366 + numOfPyung*365;
  int i = 0;
  if (calYear(yearNum) == 1) {
    while (yunMonth[i][0] != monthNum) {
      days += yunMonth[i][1];
      i++;
    }
    days += dayNum;
  }else{
    while (pyungMonth[i][0] != monthNum) {
      days += pyungMonth[i][1];
      i++;
    }
    days += dayNum;
  }
  int today = (days + 4) % 7;
  std::cout << today << '\n';
}

int calYear(int Y){
  if (Y % 400 == 0) {
    return 1;
  }else if (Y % 100 == 0) {
    return 0;
  }else if (Y % 4 == 0) {
    return 1;
  }else{
    return 0;
  }
}
