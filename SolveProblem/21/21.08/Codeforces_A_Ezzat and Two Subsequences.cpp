#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed;
	cout.precision(9);

	int T;
	cin >> T;
	while (T--) {
		vector<int> v;
		int n, mx = -2e9;
		long long sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			mx = max(mx, num);
			sum += num;
		}
		cout << mx + (double)(sum - mx)/(n - 1) << "\n";
	}
	return 0;
}