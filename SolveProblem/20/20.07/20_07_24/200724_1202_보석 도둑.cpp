#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
pair<int, int> arr[300001];
int bag[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b;
	long long ans = 0;
	priority_queue<int, vector<int>, less<int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	for (int i = 0; i < m; i++) cin >> bag[i];
	sort(arr, arr + n);
	sort(bag, bag + m);

	int idx = 0;

	for (int i = 0; i < m; i++) {
		while (idx < n && arr[idx].first <= bag[i])
			q.push(arr[idx++].second);
		
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans;
	return 0;
}