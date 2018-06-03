#include <string>
#include <iostream>

using namespace std;

int main(){
  string password;
  do {
    cout << "비밀번호는 바보\n\n";
    cout << "Please enter your password: ";
    cin >> password;
  } while(password != "바보");
  cout << "\n\n\n정답!!\n\n\n";
}
