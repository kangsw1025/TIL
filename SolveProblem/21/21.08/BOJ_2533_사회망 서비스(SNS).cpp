#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, cnt;
vector<int> v[1000001];
int dp[1000001][2];


int dfs(int cur, int pre, int use) {

	int& ret = dp[cur][use];
	if (ret != -1) return ret;

	ret = 0;

	if (use == 0) {
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];

			if (next == pre) continue;
			ret += dfs(next, cur, 1);
		}
		return ret;
	}
	else {
		int ret1 = 0, ret2 = 0;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];

			if (next == pre) continue;
			ret += min(dfs(next, cur, 0), dfs(next, cur, 1));
		}
		return ++ret;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));
	
	cout << min(dfs(1, 0, 0), dfs(1, 0, 1));

	return 0;
}