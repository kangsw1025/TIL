#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const long long mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		priority_queue<long long, vector<long long>, greater<long long>> q;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			long long val; cin >> val;
			q.push(val);
		}

		long long ans = 1;

		while (q.size() > 1) {
			long long f = q.top(); q.pop();
			long long s = q.top(); q.pop();

			long long rst = ((f % mod) * (s % mod));
			ans = (ans * (rst % mod)) % mod;
			q.push(rst);
		}


		cout << ans << "\n";
	}
	return 0;
}