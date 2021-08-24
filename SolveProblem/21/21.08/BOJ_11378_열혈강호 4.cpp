#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, k;
vector<int> v[1001];
int aMatch[1001], bMatch[1001];
bool visit[1001];

bool match(int a) {
	if (visit[a]) return false;

	visit[a] = true;

	for (int i = 0; i < v[a].size(); i++) {
		int b = v[a][i];
		if (!bMatch[b]) {
			bMatch[b] = a;
			return true;
		}
		else if (aMatch[bMatch[b]] > 1 && a != bMatch[b]) {
			aMatch[bMatch[b]]--;
			bMatch[b] = a;
			return true;
		}
		else if (match(bMatch[b])) {
			bMatch[b] = a;
			return true;
		}
	}

	return false;
}

int solve() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < v[i].size(); j++) {
			memset(visit, false, sizeof(visit));
			if (match(i)) aMatch[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (aMatch[i] > 1) {
			if (k) {
				ans += min(k, aMatch[i] - 1);
				k -= min(k, aMatch[i] - 1);
			}
			ans++;
		}
		else ans += aMatch[i];
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		while (num--) {
			int work;
			cin >> work;
			v[i].push_back(work);
		}
	}

	cout << solve();

	return 0;
}