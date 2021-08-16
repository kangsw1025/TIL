#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, ar[10002];
vector<int> v[10002];
bool visit[10002];

bool solve(int idx, int cnt) {
	if (cnt == n + 1) return true;

	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];

		if (!visit[next]) {
			ar[cnt + 1] = next;
			visit[next] = true;
			if (solve(next, cnt + 1)) return true;
			visit[next] = false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));
		memset(ar, 0, sizeof(ar));

		bool can = false;

		for (int i = 1; i <= 10001; i++)
			v[i].clear();
		cin >> n;
		for (int i = 1; i < n; i++)
			v[i].push_back(i + 1);

		for (int i = 1; i <= n; i++) {
			int op;
			cin >> op;
			if (op == 1) v[n + 1].push_back(i);
			else v[i].push_back(n + 1);
		}

		for (int i = 1; i <= n + 1; i++) {
			ar[1] = i;
			visit[i] = true;
			if (solve(i, 1)) {
				can = true;
				break;
			}
			visit[i] = false;
		}
		if (can)
			for (int i = 1; i <= n + 1; i++)
				cout << ar[i] << ' ';
		else cout << "-1";
		cout << "\n";

	}
	return 0;
}