#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "CHRISTMAS";
	string vect[100];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vect[i];
	}

	int cnt = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < n; d++) {
					string temp = vect[a] + vect[b] + vect[c] + vect[d];
					if (temp == "CHRISTMAS") cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}