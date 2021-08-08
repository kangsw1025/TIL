#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, t, k, a[2001], b[2001], dp[2001][2001];
vector<int> v[2001];

int solve(int f, int s) {
	int& rst = dp[f][s];
	if (rst != -1) return rst;
	if (f == n || s == m) return rst = 0;

	rst = solve(f + 1, s);
	auto itr = lower_bound(v[f].begin(), v[f].end(), s);
	if (itr != v[f].end()) rst = max(solve(f + 1, (*itr) + 1) + 1, rst);
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> k;
		a[k-1] = i;
	}

	for (int i = 0; i <m; i++) {
		cin >> k;
		b[k-1] = i;
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		int f, s;
		cin >> f >> s;
		v[a[f-1]].push_back(b[s-1]);
	}

	for (int i = 0; i < n; i++)
		sort(v[i].begin(), v[i].end());

	memset(dp, -1, sizeof(dp));

	cout << t - solve(0, 0);
	
	return 0;
}