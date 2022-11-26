#include <iostream>
#include <vector>

using namespace std;
int N;
int B;
int H;
int minNum = 21e8;
vector<int> hv;
void input()
{
	minNum = 21e8;
	hv.clear();
	cin >> N;
	cin >> B;
	for (int i = 0; i < N; i++)
	{
		cin >> H;
		hv.push_back(H);
	}
}

void dfs(int lev,int prev, int sumNum)
{
	if (lev == N)return;
	for (int i = prev+1; i < N; i++)
	{
		
		if (sumNum + hv[i] >= B)
		{
			minNum = min(sumNum + hv[i], minNum);
		
		}
		
		dfs(lev + 1, i, sumNum + hv[i]);
	
		
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc=1; tc <= T; tc++)
	{
		input();
		dfs(0,-1,0);
		cout << '#' << tc << ' ' << minNum - B << '\n';
	}
	

	return 0;
}