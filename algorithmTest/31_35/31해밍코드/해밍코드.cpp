#include<iostream>
#include<fstream>
using namespace std;

void changeTo2(int dif,int n,int list[33]){
	for(int i=1; i<33; i++)
	{
		if((dif==1 and n==0) or (dif==0 and (n==0 or 32%i==0)))
		{
			list[i]=0;
		}
		else if(n%2==0)
		{
			list[i]=0;
			n/=2;
		}
		else
		{
			list[i]=1;
			n/=2;
		}
	}
}
void hammingcode(int list[32]){
	for(int i=1; i<=32; i*=2)
	{
		int sum=0;
		for(int j=i; j<33; j++)
		{
			if((j/i)%2==1)
			{
				sum+=list[j];
			}
		}
		if(sum%2!=0)
		{
			list[i]=1;
		}
	}
}
void translation(int list[33]){
	int result=0;
	for(int i=1; i<=32; i*=2)
	{
		int sum=0;
		for(int j=i; j<33; j++)
		{
			if((j/i)%2==1)
			{
				sum+=list[j];
			}
		}
		if(sum%2!=0)
		{
			result+=i;
		}
	}
	list[result]==0? list[result]=1:list[result]=0;
}
int changeTo10(int dif,int list[33]){
	int result=0;
	if(dif==0)
	{
		for(int i=1; i<33; i++)
		{
			if(list[i]==1)
			{
				int n=1;
				for(int j=1; j<i; j++)
				{
					n*=2;
				}
				result+=n;

			}
		}
	}
	else
	{
		int x=1;
		for(int i=1; i<33; i++)
		{
			if(32%i!=0)
			{
				int n=1;
				for(int j=1; j<x; j++)
				{
					n*=2;
				}
				result+=list[i]*n;
				x++;
			}
		}
	}
	return result;
}

int main()
{
	ifstream is;
	is.open("input.txt");
	int numTestCases;
	is>>numTestCases;
	int dif,num;
	for(int i=0; i<numTestCases; i++)
	{
		is>>dif>>num;
		int list[33];
		if(dif==1)
		{
			changeTo2(dif,num,list);
			translation(list);
			cout<<changeTo10(dif,list)<<endl;
		}
		else
		{
			changeTo2(dif,num,list);
			hammingcode(list);
			cout<<changeTo10(dif,list)<<endl;
		}
	}
}
