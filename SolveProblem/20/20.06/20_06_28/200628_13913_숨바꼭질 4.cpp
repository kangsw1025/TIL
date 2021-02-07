#include<iostream>
#include<queue>
using namespace std;

int arr[100001];
bool check[100001];
int s, d;

void show(int n) {
	if (arr[n] != n) show(arr[n]);
	cout << n << ' ';
}

void reset() {
	for (int i = 0; i <= 100000; i++) arr[i] = i;
}

int solve() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, s));
	check[s] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int now = q.front().second;
		if (now == d) return cnt;
		q.pop();
		if (now - 1 >= 0 && !check[now - 1]) {
			check[now - 1] = true;
			arr[now - 1] = now;
			q.push(make_pair(cnt + 1, now - 1));
		}
		if (now + 1 <= d && !check[now + 1]) {
			check[now + 1] = true;
			arr[now + 1] = now;
			q.push(make_pair(cnt + 1, now + 1));
		}
		if (now * 2 <= d+2 && !check[now * 2]) {
			check[now * 2] = true;
			arr[now * 2] = now;
			q.push(make_pair(cnt + 1, now * 2));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> d;
	reset();
	int ans = solve();
	cout << ans << "\n";
	show(d);
	return 0;
}