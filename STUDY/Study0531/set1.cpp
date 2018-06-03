#include <iostream>
#include <set>
using namespace std;

void print_set(set<int>& lst)
{
	cout << "[";
	for (set<int>::iterator itr = lst.begin(); itr != lst.end(); itr++)
  {
		cout << *itr << " ";
	}
	cout << "]" << endl;
};

void print_multiset(multiset<int>& lst)
{
	cout << "[";
	for (multiset<int>::iterator itr = lst.begin(); itr != lst.end(); itr++)
  {
		cout << *itr << " ";
	}
	cout << "]" << endl;
};

void search_set(set<int>& lst, int v){
  set<int>::iterator pos = lst.find(v);
  if (pos != lst.end()) {
    std::cout << "값 " << *pos << "가 발견됨!" << '\n';
  }else{
    std::cout << "값이 발견되지 않음!" << '\n';
  }
}

int main(int argc, char const *argv[]) {
  set<int> my_set;
  multiset<int> my_multiset;

  my_set.insert(1);
  my_set.insert(2);
  my_set.insert(3);
  my_set.insert(3);
  my_set.insert(3);

  my_multiset.insert(my_set.begin(), my_set.end());
  my_multiset.insert(3);
  my_multiset.insert(4);

  search_set(my_set, 2);
  search_set(my_set, 100);

  print_set(my_set);
  print_multiset(my_multiset);
  return 0;
}
