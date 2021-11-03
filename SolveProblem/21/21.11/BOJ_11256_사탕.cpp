#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int j, n;
		cin >> j >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(a * b);
		}
		sort(v.begin(), v.end(), cmp);

		int cnt = 0, sum=0;
		for (int i = 0; i < n; i++) {
			cnt++;
			sum += v[i];
			if (sum >= j) break;
		}
		cout << cnt << "\n";
	}

	return 0;
}