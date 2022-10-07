#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
string word;

int find_idx()
{
	for (int i = 0; i < word.size() - 1; i++)
	{
		if (word[i] == word[i + 1]) return i;
	}
	return -1;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
	
		cin >> word;

		while (find_idx() !=-1)
		{
			int idx = find_idx();
			word.erase(i+1);
			word.erase(i);
		}
		if (word.size() == 0)
		{
			cout <<'#' <<tc+1<<' ' << "Good"<<'\n';
		}
		else if (word.size() != 0)
		{
			cout << word;
		}

	}




	return 0;
}