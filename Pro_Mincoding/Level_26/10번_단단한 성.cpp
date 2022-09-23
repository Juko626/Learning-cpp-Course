#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int map[4][4] = { 0,0,0,0,
			      0,1,1,0,
	              2,2,3,0,
	              1,3,3,1 };

int main()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			int max = map[3][j];
			if (map[i][j] > max)
			{
				cout << "안전하지않은성";
				return 0;
			}
		}
	}
	
	cout << "안전한성";
}