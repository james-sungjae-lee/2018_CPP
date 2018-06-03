#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

// 0 ~ RAND_MAX
using namespace std;
int arr[10000];

void get_random(int n){
  for (size_t i = 0; i < n; i++) {
    arr[i] = rand()%201 - 100;
    std::cout << arr[i] << '\n';
  }
}

void countRand(int arr[]){
  int countArr[8] = {0};
  // 질문사항 !!! countArr를 [100] 으로 하면 overflow 발생하는듯? 왜? : 당시 코드 = countArr[100];
  // 답변 : countArr 의 초기화가 이루어지지 않았기 때문!! countArr 의 각 값을 1로 초기화 시켜 주어야 한다.
  for (size_t i = 0; i < 1000; i++) {
    if (arr[i]< -75) {
      countArr[0]++;
    }else if(-75 <= arr[i] && arr[i] < -50){
      countArr[1]++;
    }else if(-50 <= arr[i] && arr[i] < -25){
      countArr[2]++;
    }else if(-25 <= arr[i] && arr[i] < 0){
      countArr[3]++;
    }else if(0 <= arr[i] && arr[i] < 25){
      countArr[4]++;
    }else if(25 <= arr[i] && arr[i] < 50){
      countArr[5]++;
    }else if(50 <= arr[i] && arr[i] < 75){
      countArr[6]++;
    }else
      countArr[7]++;
  }
  std::cout << '\n';
  std::cout << "8개로 나눈 평균 : 125개" << '\n';
  std::cout << '\n';
std::cout << " -100 ~ -75 : " ;
std::cout << countArr[0] << " 개"<<'\n';
std::cout << " -75 ~ -50 : " ;
std::cout << countArr[1] << " 개"<<'\n';
std::cout << " -50 ~ -25 : " ;
std::cout << countArr[2] <<" 개"<< '\n';
std::cout << " -25 ~ 0 : " ;
std::cout << countArr[3] << " 개"<<'\n';
std::cout << " 0 ~ 25 : " ;
std::cout << countArr[4] << " 개"<<'\n';
std::cout << " 25 ~ 50 : " ;
std::cout << countArr[5] << " 개"<<'\n';
std::cout << " 50 ~ 75 : " ;
std::cout << countArr[6] << " 개"<<'\n';
std::cout << " 75 ~ 100 : " ;
std::cout << countArr[7] << " 개"<<'\n';
}

int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  get_random(1000);
  countRand(arr);
  return 0;
}
