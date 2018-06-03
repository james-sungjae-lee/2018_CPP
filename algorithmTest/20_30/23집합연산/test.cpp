#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("input.txt");
	int numCase;

	in >> numCase;

	for(int i = 0; i < numCase; i++)
	{
		int a[132];
		int b[132];
		int dator;
		int count = 0;
		int num;
		int c[132];
		int d[132];
		int e[132];

		in >> num;

		for(int j = 0; j < 132; j ++)
		{
			a[j] = 0;
			b[j] = 0;
			c[j] = 0;
			d[j] = 0;
			e[j] = 0;
		}

		for(int j = 0 ; j < num; j++)
		{
			in >> dator;
			a[dator] = 1;
		}

		in >> num;

		for(int j = 0; j < num; j++)
		{
			in >> dator;;
			b[dator] = 1;
		}

		//교집합

		int t = 0;

		for(int j = 0; j < 132; j++)
		{
			if(a[j] == 1 && b[j] ==1)
			{
				count += 1;
				c[t] = j;
				t++;
			}
		}

		cout << count << ' ';

		for(int j = 0; j < count; j++)
		{
			cout << c[j] << ' ';
		}

		cout << endl;

		//합집합
		t = 0;
		count = 0;

		for(int j = 0; j <132; j++)
		{
			if(a[j] == 1 || b[j] == 1)
			{
				count += 1;
				d[t] = j;
				t++;
			}
		}

		cout << count << ' ';

		for(int j = 0; j < count; j++)
		{
			cout << d[j] << ' ';
		}

		cout << endl;

		//차집합

		t = 0;
		count = 0;

		for(int j = 0; j < 132; j++)
		{
			if(a[j] == 1 && b[j] == 0)
			{
				count += 1;
				e[t] = j;
				t++;
			}
		}

		cout << count << ' ' ;

		for(int j = 0; j < count; j++)
		{
			cout << e[j] << ' ';
		}

		cout << endl;

	}

	in.close();
	return 0;
}
