#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int M;
	int V;
	vector<vector<int>> alist(1000);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int srt;
		int end;
		cin >> srt >> end;
		alist[srt].push_back(end);
	}
	int de1 = 0;

	return 0;
}