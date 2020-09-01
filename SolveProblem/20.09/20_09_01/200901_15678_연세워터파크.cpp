#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int n, d;
long long now, ans = -2e9;
deque<pair<long long, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		
		while (!q.empty() && q.front().second + d < i) q.pop_front();
		if (!q.empty())
			now = max(num, num + q.front().first);
		else now = num;

		ans = max(ans, now);
		while (!q.empty() && q.back().first <= now) q.pop_back();
		q.push_back(make_pair(now, i));
	}
	cout << ans;
	return 0;
}