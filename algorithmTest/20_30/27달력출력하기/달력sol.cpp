#include <iostream>
#include <fstream>
using namespace std;

void calc();
int numTestCases;
ifstream inpf("input.txt");

int main(){
        inpf >> numTestCases;
        for(int i=0; i< numTestCases; i++){
        calc();
	}
}


void calc(){

int year, month;
inpf >> year >> month;
cout << year << " " << month << endl;

int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days = 0;
int firstdate = 0;
int count = 0;

days = (year-1)*365+((year-1)/4)-((year-1)/100)+((year-1)/400);

if(year%4==0&&year%100!=0||year%400==0){
        day[1] = 29;
}
else{
        day[1] = 28;
}

for(int j=0; j<month-1; j++){
days += day[j];
}

firstdate = days%7;

for(int j=0; j<=firstdate; j++){
if(firstdate!=6){
cout << 0 << " ";
count++;
}
}
for(int j=1; j<=day[month-1]; j++){
if(count>=7){
cout << endl;
count = 0;
}
cout << j << " ";
count++;
}

for(int j=0; j<7-count; j++){
cout << 0 << " ";
}
cout << endl;
}
