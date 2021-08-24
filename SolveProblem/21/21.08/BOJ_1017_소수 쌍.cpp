#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int n, arr[51];
int aMatch[51], bMatch[51];
bool visit[51], sosu[2001];
vector<int> v[51];

void check() {
	memset(sosu, true, sizeof(sosu));
	sosu[0] = false;
	sosu[1] = false;
	for (int i = 2; i <= 1000; i++)
		if (sosu[i])
			for (int j = 2; i * j <= 2000; j++)
				sosu[i * j] = false;
}

bool dfs(int a) {
	if (visit[a]) return false;

	visit[a] = true;

	for (auto b : v[a]) {
		if (bMatch[b] == -1 || dfs(bMatch[b])) {
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}

	return false;
}

void solve() {
	vector<int> ans;

	for (auto i : v[0]) {
		memset(aMatch, -1, sizeof(aMatch));
		memset(bMatch, -1, sizeof(bMatch));

		int cnt = 1;
		aMatch[0] = i;
		bMatch[i] = 0;

		for (int j = 1; j < n; j++) {
			memset(visit, false, sizeof(visit));
			visit[0] = true;
			cnt += dfs(j);
		}

		if (cnt == n) ans.push_back(arr[i]);
	}

	sort(ans.begin(), ans.end());

	if (!ans.empty()) for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	else cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	check();

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && sosu[arr[i] + arr[j]])
				v[i].push_back(j);

	solve();

	return 0;
}