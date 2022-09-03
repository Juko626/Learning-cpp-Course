#include<iostream>
using namespace std;
char history[10];
void recur(int lv) {
	if (lv == 3) {
		history[lv] = 0;
		int cW = 0, cL=0;
		for (int i = 0; i < 3; i++) {
			if (history[i] == 'O')
				cW++;
			if (history[i] == 'X')
				cL++;
		}
		if (cW) cout << cW << "승";
		if (cL) cout << cL << "패";
		cout << "(";
		for (int i = 0; i < 3; i++) {
			if (history[i] == 'O')
				cout << "승";
			if (history[i] == 'X')
				cout << "패";
		}
		cout << ")" << endl;
		return;
	}
		
	history[lv] = 'O';
	recur(lv + 1);
	history[lv] = 'X';
	recur(lv + 1);
}
int main() {
	recur(0);
	return 0;
}