#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//전역변수
int N;
vector<int> v;
vector<int> buho;
int pl;
int mi;
int mu;
int di;
int maxNum;
int minNum;

//함수
void input()
{
	
	cin >> N;
	cin >> pl;
	cin >> mi;
	cin >> mu;
	cin >> di;
	buho.clear();
	v.clear();
	buho.push_back(pl);
	buho.push_back(mi);
	buho.push_back(mu);
	buho.push_back(di);
	maxNum = -21e8;
	minNum = 21e8;
	for (int i = 0; i < N; i++)
	{
		int H;
		cin >> H;
		v.push_back(H);
	}
}

void DFS(int lev, int sumNum)
{
	if (lev == N-1)
	{
		maxNum = max(maxNum, sumNum);
		minNum = min(minNum, sumNum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			if (buho[i] == 0)continue;
			buho[i] -= 1;
			DFS(lev + 1, sumNum + v[lev + 1]);
			buho[i] += 1;
		}
		else if (i == 1)
		{
			if (buho[i] == 0)continue;
			buho[i] -= 1;
			DFS(lev + 1, sumNum - v[lev + 1]);
			buho[i] += 1;
		}
		else if (i == 2)
		{
			if (buho[i] == 0)continue;
			buho[i] -= 1;
			DFS(lev + 1, sumNum * v[lev + 1]);
			buho[i] += 1;
		}
		else if (i == 3)
		{
			if (buho[i] == 0)continue;
			buho[i] -= 1;
			DFS(lev + 1, sumNum / v[lev + 1]);
			buho[i] += 1;
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
		DFS(0,v[0]);
		cout << '#' << tc << ' ' << abs(maxNum - minNum) << '\n';
	}
}