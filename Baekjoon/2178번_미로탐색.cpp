#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int y;
	int x;
	int cost;
}Node;



int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };
int used[100][100];
int cost[100][100];
queue<Node> q;
int alist[100][100];


void init() {
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cost[i][j] = 10000;
		}
	}
}
int main()
{
	init();
	int y, x;
	cin >> y >> x;


	int time=1;
	for (int i = 0; i < y; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			int new_s = int(s[j] - '0');
			alist[i][j] = new_s;
		}
	};





	int de = 0;


	q.push({ 0,0,0 });
	used[0][0]=1;
	cost[0][0] = 0;
	while (!q.empty())
	{

		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];

			if (ny < 0 || nx < 0 || ny >= y || nx >= x)continue;
			//if (used[ny][nx] ==1)continue;
			if (alist[ny][nx] == 0)continue;
			if (used[ny][nx]==1) continue;
			if (cost[ny][nx] < now.cost) continue;
			q.push({ ny,nx,now.cost+1 });
			used[ny][nx] = 1;
			cost[ny][nx] = now.cost+1;
			
		}
	}
	cout << cost[y-1][x - 1]+1;


	return 0;
}