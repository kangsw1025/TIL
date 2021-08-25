#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

int n, m, s, v;
int aMatch[101], bMatch[101];
pair<double, double> mouse[101];
pair<double, double> cave[101];
vector<int> vec[101];
bool visit[101];

bool dfs(int a) {
	if (visit[a]) return false;

	visit[a] = true;

	for (int i = 0; i < vec[a].size(); i++) {
		int b = vec[a][i];

		if (!bMatch[b] || dfs(bMatch[b])) {
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}

void solve() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) cnt++;
	}

	cout << n - cnt;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> s >> v;

	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		mouse[i] = { x,y };
	}

	for (int i = 1; i <= m; i++) {
		double x, y;
		cin >> x >> y;
		for (int j = 1; j <= n; j++) {
			double dst = sqrt(pow(mouse[j].first - x, 2) + pow(mouse[j].second - y, 2));
			if (dst <= double(s*v)) vec[j].push_back(i);
		}
	}

	solve();

	return 0;
}