#include <iostream>
#include <list>
using namespace std;

template <typename T>

void print_list(list<T>& lst)
{
	cout << "[";
	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++)
  {
		cout << *itr << " ";
	}
	cout << "]" << endl;
}

int main(int argc, char const *argv[]) {
  list<int> my_list;

  for (size_t i = 1; i < 5; i++) {
    my_list.push_back(i*10);
  }

  my_list.insert(my_list.begin(), 5);
  my_list.insert(my_list.end(), 45);
  print_list(my_list);

  return 0;
}
