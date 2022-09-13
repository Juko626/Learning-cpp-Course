#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


int n;
int used[12];
int path[12];
int cnt = 0;
void dfs(int lev)
{
	if (lev == 3)
	{
		cnt++;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 1) continue;
		path[lev] = i;
		used[i] = 1;
		dfs(lev + 1);
		used[i] = 0;
	}
}


int main()
{

	cin >> n;
	dfs(0);
	cout << cnt;

}