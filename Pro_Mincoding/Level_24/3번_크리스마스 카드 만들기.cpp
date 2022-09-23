#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


string card[15];
int num;
string path[15];
int used[15] = { 0 };
string result;
int cnt = 0;
void dfs(int lev)
{
	if (lev == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			result += path[i];
		}
		if (result == "CHRISTMAS")
		{
			cnt++;
		}
		result = "";
		return;
	}
	for (int i = 0; i < num; i++)
	{
		if (used[i] == 1) continue;
		path[lev] = card[i];
		used[i] = 1;
		dfs(lev + 1);
		used[i] = 0;

	}
}
int main()
{

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> card[i];
	}

	dfs(0);
	cout << cnt;
}