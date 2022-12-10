#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int M;
int V;
vector<vector<int>> alist(10);
int used[1001];
queue<int> q;
void init()
{
	for (int i = 0; i < 1001; i++)
	{
		used[i] = 0;
	}
}
void DFS(int SRT)
{
	for (int i = 0; i < alist[SRT].size(); i++)
	{
		if (used[alist[SRT][i]] == 1) continue;
		used[alist[SRT][i]] = 1;
		cout << alist[SRT][i] << ' ';
		DFS(alist[SRT][i]);
	}
	return;
}

void BFS()
{
	
	while (!q.empty())
	{
		int now = q.front();
		cout << now << ' ';
		q.pop();
		for (int i = 0; i < alist[now].size(); i++)
		{
			if (used[alist[now][i]] == 1)continue;
			used[alist[now][i]] = 1;
			q.push(alist[now][i]);
		}
	}
}



int main()
{

	

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int srt;
		int end;
		cin >> srt >> end;
		alist[srt].push_back(end);
	}
	cout << V <<' ';
	DFS(V);
	cout << '\n';
	init();
	
	q.push(V);

	
	BFS();
	return 0;
}