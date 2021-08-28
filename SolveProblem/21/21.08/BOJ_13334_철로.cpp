#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back({ a,b });
	}
	cin >> k;

	sort(v.begin(), v.end(), cmp);
	
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(v[0].first);
	
	for (int i = 1; i < n; i++) {
		pair<int, int> p = v[i];

		q.push(p.first);

		while (!q.empty()) {
			int now = q.top();
			if (now + k >= p.second) break;
			q.pop();
		}
		
		int cnt = q.size();
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}