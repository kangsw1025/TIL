#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool visit[6][6];
string s[37];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	for (int i = 1; i <= 36; i++) {
		cin >> s[i];
	}

	visit[s[1][0] - 'A'][s[1][1] - '1'] = true;

	for (int i = 2; i <= 36; i++) {
		int o = s[i][0] - 'A';
		int t = s[i][1] - '1';
		int bo = s[i - 1][0] - 'A';
		int bt = s[i - 1][1] - '1';

		if (visit[o][t]) {
			cout << "Invalid";
			return 0;
		}
		visit[o][t] = true;

		int fd = abs(o-bo);
		int fs = abs(t-bt);
		a = b;
		if (fd == 1 && fs == 2) continue;
		if (fd == 2 && fs == 1) continue;

		cout << "Invalid";
		return 0;
	}

	int o = s[36][0] - 'A';
	int t = s[36][1] - '1';
	int bo = s[1][0] - 'A';
	int bt = s[1][1] - '1';

	int fd = abs(o - bo);
	int fs = abs(t - bt);

	if ((fd == 1 && fs == 2) || (fd == 2 && fs == 1)) {
		cout << "Valid";
	}
	else cout << "Invalid";
	return 0;
}