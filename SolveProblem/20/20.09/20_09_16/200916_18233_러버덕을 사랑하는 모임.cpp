#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, p, e;
pair<int, int> n_p[21];
vector<int> vec;
int arr[21];

void solve(int idx, int cnt, int low, int high) {
	if (cnt == p) {
		if (low <= e && high >= e) {
			int now = e;
			for (int i = 0; i < p; i++) { 
				int id = vec[i];
				arr[id] = n_p[id].first;
				now -= arr[id];
			}
			for (int i = 0; i < p; i++) {
				if (now == 0) break;
				int id = vec[i];
				arr[id] += min(now, n_p[id].second - n_p[id].first);
				now -= min(now, n_p[id].second - n_p[id].first);
			}
			for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
			exit(0);
		}
	}
	else if (idx < n) {
		vec.push_back(idx + 1);
		solve(idx + 1, cnt + 1, low + n_p[idx + 1].first, high + n_p[idx + 1].second);

		vec.pop_back();
		solve(idx + 1, cnt, low, high);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> e;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		n_p[i] = { a, b };
	}

	solve(0, 0, 0, 0);
	cout << -1;
	return 0;
}