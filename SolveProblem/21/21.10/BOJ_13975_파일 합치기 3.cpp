#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		priority_queue<long long, vector<long long>, greater<long long>> q;
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			q.push(val);
		}

		while (q.size() != 1) {
			long long f = q.top();
			q.pop();
			long long s = q.top();
			q.pop();

			ans += f + s;
			q.push(f + s);
		}

		cout << ans << "\n";
	}
	return 0;
}