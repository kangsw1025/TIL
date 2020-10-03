#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, ans;
int pw[7];
bool check[10];

void solve(int len, int use) {
	if (len == n) {
		if (use == m) ans++;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (check[i]) {
			check[i] = false;
			solve(len + 1, use + 1);
			check[i] = true;
		}
		else solve(len + 1, use);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> pw[i];
		check[pw[i]] = true;
	}
	solve(0, 0);
	cout << ans;
	return 0;
}