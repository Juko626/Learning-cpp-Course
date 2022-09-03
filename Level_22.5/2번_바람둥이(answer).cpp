#include <iostream>
using namespace std;

int n;
char path[10];
char name[3] = "xo";

void run(int level)
{
	if (level == n)
	{
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		path[level] = name[i];
		run(level + 1);
		path[level] = 0;
	}
}

int main()
{
	cin >> n;
	run(0);

	return 0;
}