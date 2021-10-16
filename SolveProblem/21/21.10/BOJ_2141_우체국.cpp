#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
pair<int, int> p[100001];
vector<long long> sum;

int solve() {
	int l = 0, r = n - 1;
	int ans = 2e9 + 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		long long ls = sum[mid];
		long long rs = sum[n - 1] - ls;

		if (ls >= rs) {
			r = mid - 1;
			ans = min(ans, p[mid].first);
		}
		else {
			l = mid + 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> p[i].first >> p[i].second;
	
	sort(p, p + n);
	sum.push_back(p[0].second);
	for (int i = 1; i < n; i++)
		sum.push_back(sum[i - 1] + p[i].second);


	cout << solve();

	return 0;
}