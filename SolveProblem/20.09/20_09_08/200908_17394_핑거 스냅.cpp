#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

bool check[1000001], visit[1000001];
int T;

void sosu() {
	for (int i = 2; i <= 500000; i++) {
		if (!check[i])
			for (int j = 2; i * j <= 1000000; j++)
				check[i * j] = true;
	}
}

int solve(int n, int a, int b) {
	visit[n] = true;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(0, n));
	while (!q.empty()) {
		int now = q.top().second;
		int cnt = q.top().first;
		q.pop();
		if (now >= a && now <= b && !check[now]) return cnt;
		else {
			if (now) {
				if (!visit[now / 2]) {
					visit[now / 2] = true;
					q.push(make_pair(cnt + 1, now / 2));
				}
				if (!visit[now / 3]) {
					visit[now / 3] = true;
					q.push(make_pair(cnt + 1, now / 3));
				}
			}
			if (now < 1000000) {
				if (!visit[now + 1]) {
					visit[now + 1] = true;
					q.push(make_pair(cnt + 1, now + 1));
				}
			}
			if (now >= 1) {
				if (!visit[now - 1]) {
					visit[now - 1] = true;
					q.push(make_pair(cnt + 1, now - 1));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sosu();
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, a, b;
		memset(visit, 0, sizeof(visit));
		cin >> n >> a >> b;
		cout << solve(n, a, b) << "\n";
	}
	return 0;
}