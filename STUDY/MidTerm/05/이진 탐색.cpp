#include <iostream>
using namespace std;

int binarySearch(int list[], int n, int key){
  int low, high, middle;
  low = 0;
  high = n - 1;
  while (low <= high) {
    middle = (low + high)/2;
    if (key == list[middle]) {
      std::cout << middle + 1 << "번째에서 찾음!" << '\n';
      return middle;
    }else if (key > list[middle]) {
      low = middle + 1;
    }else{
      high = middle - 1;
    }
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  int myList[5] = {1, 2, 3, 4, 5};
  binarySearch(myList, 5, 2);
  return 0;
}
