#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int arr[500001][2];

int solve(int n, int m) {

	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	int ans = -1;

	while (!q.empty()) {
		int cnt = q.front().second;
		int su = q.front().first;
		q.pop();

		int ch = cnt % 2;
		if (su < 0 || su>500000) continue;
		if (arr[su][ch] != -1) continue;
		arr[su][ch] = cnt;

		q.push(make_pair(su - 1, cnt + 1));
		q.push(make_pair(su + 1, cnt + 1));
		q.push(make_pair(su * 2, cnt + 1));
	}

	int sum;

	for (int i = 0;; i++) {
		sum = m + i * (i + 1) / 2;
		if (sum > 500000) break;

		if (arr[sum][i % 2] != -1 && arr[sum][i % 2] <= i) {
			ans = i;
			break;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	cout << solve(n, m);
	return 0;
}