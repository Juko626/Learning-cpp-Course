#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
int new_map[3][3];
int map_a[3][3];
int map_b[3][3];

void sw()
{
	for (int j = 2; j >= 0; j--)
	{
		for (int i = 0; i < 3; i++)
		{
			new_map[2-j][i]=map_a[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map_a[i][j] = new_map[i][j];
		}
	}
}

int cnt = 0;
int same_map()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map_a[i][j] == map_b[i][j]) continue;
			else if (map_a[i][j] != map_b[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map_a[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map_b[i][j];
		}
	}



	for (int i = 0; i < 4; i++)
	{
		sw();

		cnt++;
		if (same_map() == 1)
		{
			cout << cnt;
			return 0;
		}
	}
}