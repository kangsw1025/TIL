#include<iostream>
#include<string>
using namespace std;

int n;
string word;

void left(int idx, char w) {
	if (word[idx] == '?') {
		if (w == 'R') word[idx] = 'B';
		else word[idx] = 'R';
	}

	if (idx == 0) return;
	left(idx - 1, word[idx]);
}

void right(int idx, char w) {
	if (word[idx] == '?') {
		if (w == 'R') word[idx] = 'B';
		else word[idx] = 'R';
	}
	if (idx == n - 1) return;
	right(idx + 1, word[idx]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		bool check = false;

		cin >> n;
		cin >> word;

		for (int i = 0; i < n; i++) {
			if (word[i] != '?') {
				if (i > 0) left(i - 1, word[i]);
				if (i < n - 1) right(i + 1, word[i]);
				check = true;
				break;
			}
		}
		if (!check)
			for (int i = 0; i < n; i++) {
				if (i % 2) word[i] = 'R';
				else word[i] = 'B';
			}

		cout << word << "\n";
	}
	return 0;
}