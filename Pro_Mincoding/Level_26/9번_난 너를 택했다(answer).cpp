#include<iostream>
using namespace std;
int main() {
	char str[20];
	int data[4];
	cin >> str;
	for (int i = 0; i < 4; i++)
		cin >> data[i];
	char *ptrs[4];
	for (int i = 0; i < 4; i++) {
		int idx = data[i];
		ptrs[i] = &str[idx];
	}
	for (int i = 0; i < 4; i++) {
		cout << *ptrs[i];
	}
	return 0;
}