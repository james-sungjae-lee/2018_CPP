#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int checkRow(int check[25])
{
	if(check[0] and check[1] and check[2] and check[3] and check[4])
		return 1;
	if(check[5] and check[6] and check[7] and check[8] and check[9])
		return 1;
	if(check[10] and check[11] and check[12] and check[13] and check[14])
		return 1;
	if(check[15] and check[16] and check[17] and check[18] and check[19])
		return 1;
	if(check[20] and check[21] and check[22] and check[23] and check[24])
		return 1;

	return 0;

}

int checkColumn(int check[25]){
	if(check[0] and check[5] and check[10] and check[15] and check[20] )
	return 1;
	if(check[1] and check[6] and check[11] and check[16] and check[21])
	return 1;
	if(check[2] and check[7] and check[12] and check[17] and check[22])
	return 1;
	if(check[3] and check[8] and check[13] and check[18] and check[23])
	return 1;
	if(check[4] and check[9] and check[14] and check[19] and check[24])
	return 1;

	return 0;
}

int check1(int check[25]){
	if(check[0] and check[6] and check[12] and check[18] and check[24])
	return 1;
	if(check[4] and check[8] and check[12] and check[16] and check[20])
	return 1;

	return 0;
}
int check2(int check[25]){
	if(check[0] and check[4] and check[20] and check[24])
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
	for(int i=0; i<numTestCases; i++)
	{
		int result=0;
		int inNum[25]={0};
		int check[25]={0};
		check[12]=1;
		/*make bingo*/
		for(int j=0; j<25; j++)
		{
			is>>inNum[j];
		}
		/*check bingo */

		int num;
		for(int j=1; j<76; j++)
		{
			is>>num;
			for(int k=0; k<25; k++)
			{
				if(num==inNum[k])
				{
					check[k]=1;
				}
			}
			if(result!=0);
			else if(checkRow(check)==1)
			{
				result=j;
			}
			else if(checkColumn(check)==1)
			{
				result=j;
			}
			else if(check1(check)==1)
			{
				result=j;
			}
			else if(check2(check)==1)
			{
				result=j;
			}
		}
		cout<<result<<endl;
	}
}
