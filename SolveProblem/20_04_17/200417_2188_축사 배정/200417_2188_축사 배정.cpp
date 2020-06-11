#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int v[201];
int c[201];
vector<vector<int>> vec;
int n, m;

int dfs(int h)
{
	if (v[h]) return 0;
	v[h] = 1;

	for (int i = 0; i < vec[h].size(); i++) {
		int t = vec[h][i];

		if (!c[t] || dfs(c[t])) {
			c[t] = h;
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vec.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			vec[i].push_back(b);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof(v));
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}