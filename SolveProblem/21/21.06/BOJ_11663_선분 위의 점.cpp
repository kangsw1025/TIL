#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());

	for (int i = 0; i < m; i++) {
		int u, v, l, r;
		cin >> u >> v;
		l = lower_bound(vec.begin(), vec.end(), u) - vec.begin();
		auto itr = upper_bound(vec.begin(), vec.end(), v);
		if (itr == vec.end()) r = vec.size()-1;
		else r = itr - vec.begin() - 1;
		cout << r - l + 1 << "\n";
	}
	return 0;
}