#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");	//open input file
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> numTestCases;	//read the number of test cases.

	for (int i = 0; i < numTestCases; i++)
	{
		long numIntegers, value;
		long result = 1;

		inStream >> numIntegers;

		for (int j = 0; j < numIntegers; j++)
		{
			inStream >> value;
			result *= value;
			result %= 100000;//수시로 나눠주기
		}
		cout << result%10 << endl;				//마지막으로 1의 자리 남기기
	}
	inStream.close();			//close input file
}
