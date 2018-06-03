#include<iostream>
#include<fstream>

using namespace std;

int countOne(int num) {
	int cnt = 0;
	while (num) {
               	if (num % 2 == 1) {
                       	cnt++;
		}
                num /= 2;
        }
        return cnt;
}

int main() {
        int numTestCases;
        ifstream in;
        in.open("input.txt");
        in >> numTestCases;
        while (numTestCases--) {
                int num1, num2;
                in >> num1 >> num2;
                cout << countOne(num1) << " " << countOne(num2) << " " << countOne(num1 ^ num2) << endl;
        }
}
