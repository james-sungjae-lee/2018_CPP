#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

void GetScore(int* arr, int size)
{
	int i;
	int* checkarr = new int[size * 2];
	int count = 0;
	int count2 = 2;

	checkarr[0] = arr[0];
	checkarr[1] = 1;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			checkarr[count + 1] += 1;
		else
		{
			count += 2;
			checkarr[count] = arr[i + 1];
			checkarr[count + 1] = 1;
			count2 += 2;
		}
	}

	for (i = 0; i < count2; i++)
		cout << checkarr[i] << " ";
	cout << endl;

	delete[] checkarr;
}

int main(void)
{
	int i, j;
	int testcases;
	int num, temp;
	int *arr;

	ifstream file;
	file.open("input.txt");

	file >> testcases;
	while (testcases--)
	{
		file >> num;
		arr = new int[num];
		for (i = 0; i < num; i++)
			file >> arr[i];

		for (i = 0; i < num - 1; i++)
		{
			for (j = 0; j < num - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		GetScore(arr, num);
		delete[] arr;
	}
	file.close();
	return 0;
}
