#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		vector<int> vec(n);
		for (int i = 0; i < n; i++) cin >> vec[i];
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size() - 2; i++) {
			ans = max(ans, abs(vec[i] - vec[i + 2]));
		}
		cout << ans << "\n";
	}
	return 0;
}