#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

double arr[51];
int n, ans;
int see[51][51];

int check(int u, int v) {
	int& rst = see[u][v];

	if (rst != -1) return rst;

	rst = 0;

	double slope = (arr[v] - arr[u]) / (v - u);

	bool is = false;

	for (int i = u + 1; i < v; i++)
		if (arr[i] >= (arr[u] + (i - u) * slope)) is = true;

	if (!is) rst = 1;

	return rst;
}

int solve(int idx) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		if (i < idx) {
			if (check(i, idx)) cnt++;
		}
		else if (i > idx) {
			if (check(idx, i)) cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	memset(see, -1, sizeof(see));

	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i));

	cout << ans;
	return 0;
}