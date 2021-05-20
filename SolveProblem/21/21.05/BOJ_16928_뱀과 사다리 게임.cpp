#include<iostream>
#include<queue>
using namespace std;

int ladder[101], snake[101];
bool check[101];

int solve() {
	queue<pair<int, int>> q;
	q.push({ 0,1 });
	check[1] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int place = q.front().second;
		q.pop();

		if (place == 100) return cnt;
		for (int i = 1; i <= 6; i++) {
			int num = place + i;
			if (check[num]) continue;
			check[num] = true;
			if (ladder[num]) q.push({ cnt + 1,ladder[num] });
			if (snake[num]) q.push({ cnt + 1,snake[num] });
			else q.push({ cnt + 1,num });

		}
	}
}

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			ladder[a] = b;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			snake[a] = b;
		}
		cout << solve();
		return 0;
	}
