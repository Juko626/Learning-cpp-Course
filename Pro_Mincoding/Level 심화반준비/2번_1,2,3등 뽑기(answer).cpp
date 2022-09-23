#include <iostream>
using namespace std;

int n;
int cnt;
int used[4];

void run(int level)
{
	if (level == 3) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			run(level + 1);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	run(0);
	cout << cnt;

	return 0;
}