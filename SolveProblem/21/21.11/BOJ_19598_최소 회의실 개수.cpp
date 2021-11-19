#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector < pair<long long, long long >> v;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long s, t;
		cin >> s >> t;
		v.push_back({ s,t });
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < n; i++) {
		long long s = v[i].first;
		long long e = v[i].second;

		if (q.empty()) q.push(e);
		else {
			if (!q.empty() && q.top() <= s) q.pop();
			q.push(e);
		}
		int q_size = q.size();
		ans = max(ans, q_size);
	}
	cout << ans;
	return 0;
}