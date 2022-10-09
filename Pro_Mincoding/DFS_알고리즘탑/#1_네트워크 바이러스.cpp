#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int cnt_com;
int arr[101][101] = { 0 };
int used[101] = { 0 };
void dfs(int srt)
{
	for (int i = 1; i <= cnt_com; i++)
	{
		if (arr[srt][i] == 1)
		{
			if (used[i] == 1) continue;
			used[i] = 1;
			dfs(i);

		}
	}
}

int main()
{

	cin >> cnt_com;



	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y;
		int x;
		cin >> y;
		cin >> x;
		arr[y][x] = 1;
		arr[x][y] = 1;
	}
	int de = 0;
	int cnt = 0;
	used[1] = 1;
	dfs(1);
	for (int i = 2; i <= 100; i++)
	{
		if (used[i] == 1) cnt++;
	}
	cout << cnt;



	return 0;
}