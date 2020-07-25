#include<iostream>
#include<queue>
using namespace std;

int arr[1000001];
bool check[1000001];

void show(int n) {
	if (arr[n] != n) show(arr[n]);
	cout << n << ' ';
}

void reset(int n) {
	for (int i = n; i >= 1; i--) arr[i] = i;
}

int solve(int n) {
	check[n] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(0, n));
	while (!q.empty()) {
		int cnt = q.front().first;
		int now = q.front().second;
		q.pop();
		if (now == 1) return cnt;
		if (now % 3 == 0 && !check[now / 3]) {
			check[now / 3] = true;
			arr[now / 3] = now;
			q.push(make_pair(cnt + 1, now / 3));
		}
		if (now % 2 == 0 && !check[now / 2]) {
			check[now / 2] = true;
			arr[now / 2] = now;
			q.push(make_pair(cnt + 1, now / 2));
		}
		if (now > 1 && !check[now - 1]) {
			check[now - 1] = true;
			arr[now - 1] = now;
			q.push(make_pair(cnt + 1, now - 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	reset(n);
	int ans = solve(n);
	cout << ans << "\n";
	show(1);
	return 0;
}