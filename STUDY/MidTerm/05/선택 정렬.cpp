#include <iostream>
using namespace std;
const int SIZE = 10;

void selectionSort(int list[], int n);
void printList(int list[], int n);

int main(int argc, char const *argv[]) {
  int grade[SIZE] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};

  printList(grade, SIZE);

  selectionSort(grade, SIZE);

  printList(grade, SIZE);
  return 0;
}

void printList(int list[], int n){
  for (size_t i = 0; i < n; i++) {
    std::cout << list[i] << " ";
  }
  std::cout << '\n';
}

void selectionSort(int list[], int n){
  int temp, min;
  for (size_t i = 0; i < n-1; i++) {
    min = i;
    for (size_t j = i + 1; j < n; j++) {
      if (list[j] < list[min]) {
        min = j;
      }
      temp = list[i];
      list[i] = list[min];
      list[min] = temp;
    }
  }
}
