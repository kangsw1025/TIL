#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
int Bit, ans = 2e9;
long long bit[11];

int countb(long long bt) {
	int rst = 0;
	while (bt) {
		rst += bt & 1;
		bt >>= 1;
	}
	return rst;
}

void solve(int idx, int cnt, long long bt) {
	int c = countb(bt);

	if (c > Bit) {
		Bit = c;
		ans = cnt;
	}
	else if (Bit == c) ans = min(ans, cnt);

	if (idx == n) return;

	solve(idx + 1, cnt + 1, bt | bit[idx]);
	solve(idx + 1, cnt, bt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string word, w;
		cin >> word >> w;
		for (int j = 0; j < m; j++) {
			if (w[j] == 'Y') bit[i] |= (1LL << (m - 1 - j));
		}
	}

	solve(0, 0, 0);

	if (!Bit) cout << -1;
	else cout << ans;

	return 0;
}