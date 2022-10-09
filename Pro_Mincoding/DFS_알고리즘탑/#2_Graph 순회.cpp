#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> alist(101);

int used[101];


void init()
{
	for (int i = 0; i < 101; i++)
	{
		used[i] = 0;
	}
}


void dfs_pre(int start)
{
	used[start] = 1;
	cout << start << ' ';
	for (int i = alist[start].size()-1; i >=0; i--)
	{
		if (used[alist[start][i]] == 1) continue;
		used[alist[start][i]] = 1;
		dfs_pre(alist[start][i]);
	}
	return;
}

void dfs_pos(int start)
{
	used[start] = 1;
	
	for (int i = alist[start].size() - 1; i >= 0; i--)
	{
		if (used[alist[start][i]] == 1) continue;
		used[alist[start][i]] = 1;
		dfs_pos(alist[start][i]);
		
	}
	cout << start << ' ';
	return;
}


int main()
{

	int N;
	cin >> N;
	int K;
	cin >> K;
	int srt;
	cin >> srt;
	
	for (int i = 0; i < K; i++)
	{
		int z;
		int x;
		cin >> z;
		cin >> x;
		alist[z].push_back(x);
	}
	for (int i = 0; i <= N; i++)
	{
		sort(alist[i].begin(), alist[i].end());
	}

	dfs_pre(srt);
	cout << "\n";
	init();
	dfs_pos(srt);


	return 0;
}