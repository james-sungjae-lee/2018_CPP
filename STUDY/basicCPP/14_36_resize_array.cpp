#include <iostream>

using namespace std;

int *growArray (int *p_values, int *size);
void printArray(
  int *p_values,
  int size,
  int elements_set
);

int main(int argc, char const *argv[]) {
  int next_elements = 0;
  int size = 10;
  int *p_values = new int[size];
  int val;
  std::cout << "Please enter a number: " << '\n';
  cin >> val;
  while (val > 0) {
    if (size == next_elements + 1) {
      p_values = growArray(p_values, &size);
    }
    p_values[next_elements] = val;
    next_elements++;
    std::cout << "Current array values are: " << '\n';
    printArray(p_values, size, next_elements);
    std::cout << "Please enter a number (or 0 to exit): " << '\n';
    cin >> val;
  }
  delete [] p_values;
}

void printArray(int *p_values, int size, int elements_set) {
  std::cout << "The total size of the array is: " << size << '\n';
  std::cout << "Number of slots set so far: " << elements_set << endl;
  std::cout << "Vlaes in the array: " << endl;
  for (int i = 0; i < elements_set; ++i) {
    std::cout << "p_values[" << i << "] = " << p_values[i] << endl;
  }
}

int *growArray(int *p_values, int *size){
  *size *= 2;
  int *p_new_values = new int[*size];
  for (size_t i = 0; i < *size; ++i) {
    p_new_values[i] = p_values[i];
  }
  delete[] p_values;
  return p_new_values;
}
