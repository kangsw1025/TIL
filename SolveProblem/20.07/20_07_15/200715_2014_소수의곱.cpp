#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

long long arr[100001];
priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		q.push(arr[i]);
	}
	int ans;

	for (int i = 0; i < m; i++) {
		ans = q.top();
		q.pop();

		for (int j = 0; j < m; j++) {
			q.push(ans * arr[j]);
			if (ans % arr[j] == 0) break;
		}
	}
	cout << ans;
	return 0;
}