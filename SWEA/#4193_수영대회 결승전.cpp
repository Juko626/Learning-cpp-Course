#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//전역 변수
int N;
int srty, srtx;
int endy, endx;
int map[15][15];
int visit[15][15];
int direct_Y[4] = { -1,1,0,0 };
int direct_X[4] = { 0,0,-1,1 };
typedef struct {
	int y;
	int x;
	int t;
}Node;
queue<Node> q;

//함수
void init()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			visit[i][j] = 21e8;
		}
	}
}
void input()
{
	cin >> N;
	queue<Node> q;
	init();
	for (int row=0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> map[row][col];
		}
	}
	cin >> srty >> srtx;
	cin >> endy >> endx;
	

}


void BFS()
{
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		int dy = now.y;
		int dx = now.x;
		int dt = now.t;
		for (int i = 0; i < 4; i++)
		{
			int ny = dy + direct_Y[i];
			int nx = dx + direct_X[i];
			//int dt = now.t;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			
			//if (visit[ny][nx] != 21e8) continue;
			if (dt+1 > visit[ny][nx]) continue;
			//if (visit[ny][nx] < dt + 4) return;
			if (visit[ny][nx] < dt + 1) continue;
			if (map[ny][nx] == 0)
			{
				visit[ny][nx] = dt + 1;
				q.push({ ny,nx,dt + 1 });
			}
			else if (map[ny][nx] == 1) continue;
			else if (map[ny][nx] == 2)
			{
				if (dt % 3 == 0)
				{
					//dt+=2;
					if (visit[ny][nx] < dt + 3) continue;
					visit[ny][nx] = dt + 3;
					q.push({ ny,nx,dt + 3 });
				}
				else if (dt % 3 == 1)
				{
					//dt += 1;
					if (visit[ny][nx] < dt + 2) continue;
					visit[ny][nx] = dt + 2;
					q.push({ ny,nx,dt + 2 });
				}
				else if (dt % 3 == 2)
				{
					if (visit[ny][nx] < dt + 1) continue;
					visit[ny][nx] = dt + 1;
					q.push({ ny,nx,dt + 1 });
					continue;
				}
			}
			
			
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		visit[srty][srtx] = 0;
		q.push({ srty,srtx,0 });
		BFS();
		if (visit[endy][endx] == 21e8)
		{
			cout << '#' << tc << ' ' <<  -1 << '\n';
		}
		else cout << '#' << tc << ' ' << visit[endy][endx] << '\n';
	}



	return 0;
}