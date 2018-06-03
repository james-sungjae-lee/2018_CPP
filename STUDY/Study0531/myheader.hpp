#ifndef _MYHEADER_H_
#define _MYHEADER_H_

#include <iostream>
using namespace std;

template<typename T>
void print(const T& v, const char* message=""){
  typename T::const_iterator it;
  cout << message;
  cout << " ( ";
  for(it = v.begin(); it != v.end(); ++it){
    cout << *it << " ";
  }
  cout << " ) " << endl;
}
#endif
