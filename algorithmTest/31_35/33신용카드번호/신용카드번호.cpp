/* 신용카드번호
  소프트웨어학부 20162772 박지희*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int checkCorp(string num){
	if((num.at(0)=='3' and (num.length()==15 or num.length()==14)) or((num.at(0)=='6' or num.at(0)=='5') and num.length()==16) or(num.at(0)=='4' and (num.length()==13 or num.length()==16)))
	{
		return 1;
	}
	return 0;
}
int checkSum(string num){
	int sum=0;
	int n=2;
	for(int i=num.length()-2; i>=0; i--)
	{
		if(n%2==0)
		{
			if(((int)num.at(i)-48)>4)
			{
				sum+=((((int)num.at(i)-48)*2)-9);
			}
			else
			{
				sum+=(((int)num.at(i)-48)*2);
			}
		}
		else
		{
			sum+=(int)num.at(i)-48;
		}
		n++;
	}
	int i=0;
	while(sum%10!=0)
	{
		sum++;
		i++;
	}
	if(((int)num.at(num.length()-1)-48)==i)
	{
		return 1;
	}
	return 0;

}
int main()
{
	ifstream is;
	is.open("input.txt");
	int numTestCases;
	is>>numTestCases;
	string num;
	int result;
	for(int i=0; i<numTestCases;i++)
	{
		is>>num;
		result=checkCorp(num);
		if(result==1)
		{
			result=checkSum(num);
		}
		cout<<result<<endl;;

	}

}
