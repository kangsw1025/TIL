#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[300001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long ans = 0;

	for (int i = 1; i < n; i++) {
		int diff = arr[i] - arr[i - 1];
		v.push_back(diff);
		ans += diff;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < k - 1; i++) ans -= v[i];
	cout << ans;
	return 0;
}