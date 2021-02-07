#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[15][15];
int dp[1 << 15][15][10];

int solve(int now, int people, int cost, int cnt) {
	int& idx = dp[now][people][cost];
	if (idx != 0) return idx;
	idx = cnt;

	for (int i = 0; i < n; i++) {
		if (now & (1 << i) || arr[people][i] < cost) continue;
		idx = max(idx, solve(now | (1 << i), i, arr[people][i], cnt + 1));
	}

	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			char w;
			cin >> w;
			arr[i][j] = w - '0';
		}

	cout << solve(1, 0, 0, 1);

	return 0;
}