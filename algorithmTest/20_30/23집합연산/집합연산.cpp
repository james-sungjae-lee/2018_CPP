#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
ifstream inStream;

int setCal();

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     setCal();
     std::cout << '\n';
     std::cout << '\n';
   }

  inStream.close();
  return 0;
}

int setCal(){
  unsigned int arr1[100] = {0};
  unsigned int arr2[100] = {0};
  int setNum1, setNum2;
  int k;
  std::vector<unsigned int> setInter;
  std::vector<unsigned int> unionSet;
  std::vector<unsigned int> unionSet2;
  std::vector<unsigned int> setDiffer;

  // 배열1, 2에 집합 원소 저장.

  inStream >> setNum1;
  for (size_t i = 0; i < setNum1; i++) {
    inStream >> k;
    arr1[i] = k;
    std::cout << arr1[i] << " ";
  }

  std::cout  << '\n';
  inStream >> setNum2;
  for (size_t i = 0; i < setNum2; i++) {
    inStream >> k;
    arr2[i] = k;
    std::cout << arr2[i] << " ";
  }
  std::cout << '\n';

  // 교집합의 원소 개수 cnt 저장 및 출력. 교집합 원소를 setInter 벡터에 저장.

  int cnt = 0;
  for (size_t i = 0; i < setNum1; i++) {
    for (size_t j = 0; j < setNum2; j++) {
      if (arr1[i] == arr2[j]) {
        cnt ++;
      }
    }
  }
  std::cout << cnt << " ";

  for (size_t i = 0; i < setNum1; i++) {
    for (size_t j = 0; j < setNum2; j++) {
      if (arr1[i] == arr2[j]) {
        setInter.push_back(arr1[i]);
      }
    }
  }

  // setInter 벡터 출력.

  sort(setInter.begin(), setInter.end());
  for (size_t i = 0; i < cnt; i++) {
    std::cout << setInter[i] << " ";
  }

  // 합집합 구하기 = 두 집합을 더하기 + 교집합을 빼기

  int cnt2 = setNum1 + setNum2;
  for (size_t i = 0; i < setNum1; i++) {
    unionSet.push_back(arr1[i]);
  }
  for (size_t i = 0; i < setNum2; i++) {
    unionSet.push_back(arr2[i]);
  }


  sort(unionSet.begin(), unionSet.end());

  int cnt3 = 0;
  for (size_t i = 0; i < cnt2; i++) {
    if (unionSet[i] != unionSet[i + 1]) {
      unionSet2.push_back(unionSet[i]);
      cnt3++;
    }
  }

  std::cout  << '\n';
  std::cout << cnt3 << " ";
  for (size_t i = 0; i < cnt3; i++) {
    std::cout << unionSet2[i] << " ";
  }
  std::cout << '\n';
  int cnt4 = 0;
  for (size_t i = 0; i < cnt; i++) {
    for (size_t j = 0; j < setNum1; j++) {
      if (setInter[i] != arr1[j]) {
        setDiffer.push_back(arr1[j]);
        std::cout << setDiffer[i] << " ";
        cnt4++;
      }
    }
  }








  return 0;
}
