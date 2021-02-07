#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, k;
int amatch[501];
int bmatch[501];
vector<int> vec[501];

int visit[501];
int visitcnt;

bool dfs(int num) {
	if (visit[num] == visitcnt) return false;
	visit[num] = visitcnt;

	for (int i = 0; i < vec[num].size(); i++) {
		int t = vec[num][i];

		if (bmatch[t] == -1 || dfs(bmatch[t])) {
			bmatch[t] = num;
			amatch[num] = t;
			return true;
		}
	}
	return false;
}

int solve() {
	memset(amatch, -1, sizeof(amatch));
	memset(bmatch, -1, sizeof(bmatch));

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		visitcnt++;
		ans += dfs(i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}

	cout << solve();
	return 0;
}