#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream instream("input.txt");
	if (!instream.is_open())
		return 1;

	int result;
	int num, strike, ball, testnum;
	int testn[4], checkn[4];
	int cstrike, cball;

	int rep;
	instream >> rep;
	for (int i = 0; i < rep; i++){
		int check[10000];
		for (int j = 0; j < 10000; j++)
			check[j] = 1;
		instream >> testnum;

		for (int j = 0; j < testnum; j++){
			instream >> num >> strike >> ball;

			testn[0] = num / 1000;
			testn[1] = (num / 100) % 10;
			testn[2] = (num / 10) % 10;
			testn[3] = num % 10;
			for (int k = 0; k < 10000; k++){
				cstrike = cball = 0;

				if (check[k] != 0){
					checkn[0] = (k / 1000) % 10;
					checkn[1] = (k / 100) % 10;
					checkn[2] = (k / 10) % 10;
					checkn[3] = k % 10;

					for (int l = 0; l < 4; l++){
						if (testn[l] == checkn[l])
							cstrike++;
						else{
							for (int m = 0; m < 4; m++){
								if (testn[l] == checkn[m] && testn[m] != checkn[m]){
									cball++;
									break;
								}
							}
						}
					}

					if ((strike != cstrike) || (ball != cball))
						check[k] = 0;
				}
			}
		}

		result = 0;
		for (int j = 0; j < 10000; j++){
			if (check[j] != 0)
				result++;
		}


		if (result == 1){
			for (int j = 0; j < 10000; j++){
				if (check[j] != 0){
					cout << j << endl;
					break;
				}
			}
		}
		else if (result > 1)
			cout << "-1" << endl;
		else
			cout << "-2" << endl;


	}
	return 0;
}
