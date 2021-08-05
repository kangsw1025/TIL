#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> hate[101];
vector<int> cnt[3];
int team[101];
bool visit[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t, h;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> h;
			hate[i].push_back(h);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;

		cnt[1].push_back(i);
		team[i] = 1;

		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < hate[cur].size(); j++) {
				int hater = hate[cur][j];

				if (visit[hater]) continue;

				visit[hater] = true;
				team[hater] = 3 - team[cur];
				cnt[3 - team[cur]].push_back(hater);
				q.push(hater);
			}
		}
	}


	sort(cnt[2].begin(), cnt[2].end());
	sort(cnt[1].begin(), cnt[1].end());

	if (cnt[2].size() == n) {
		cout << n - 1 << "\n";
		for (int i = 0; i < n - 1; i++) cout << cnt[2][i] << ' ';
		cout << "\n1\n" << cnt[0][n - 1];
		return 0;
	}

	if (cnt[1].size() == n) {
		cout << n - 1 << "\n";
		for (int i = 0; i < n - 1; i++) cout << cnt[1][i] << ' ';
		cout << "\n1\n" << cnt[1][n - 1];
		return 0;
	}

	cout << cnt[2].size() << "\n";
	for (int i = 0; i < cnt[2].size(); i++)
		cout << cnt[2][i] << ' ';
	cout << "\n";
	cout << cnt[1].size() << "\n";
	for (int i = 0; i < cnt[1].size(); i++)
		cout << cnt[1][i] << ' ';

	return 0;
}