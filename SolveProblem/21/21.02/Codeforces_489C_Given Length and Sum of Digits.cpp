#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int m, s;
	cin >> m >> s;

	string ans1, ans2;

	if (s == 0) {
		if (m == 1) cout << "0 0";
		else cout << "-1 -1";
		return 0;
	}

	for (int i = 0; i < m; i++) {
		ans1 += min(s, 9) + '0';
		s -= min(s, 9);
	}

	if (s > 0) {
		cout << "-1 -1";
		return 0;
	}

	ans2 = ans1;
	reverse(ans1.begin(), ans1.end());

	int idx = 0;

	while (ans1[idx] == '0') idx++;

	ans1[idx]--;
	ans1[0]++;

	cout << ans1 << ' ' << ans2;
	return 0;
}