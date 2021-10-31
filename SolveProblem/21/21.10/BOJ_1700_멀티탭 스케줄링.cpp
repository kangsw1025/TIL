#include<iostream>
#include<vector>
using namespace std;

int arr[101];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];

	for (int i = 0; i < k; i++) {
		int flag = 0;

		for (int j = 0; j < v.size(); j++)
			if (v[j] == arr[i]) flag = 1;

		if (flag) continue;

		if (v.size() < n) {
			v.push_back(arr[i]);
			continue;
		}

		int md = 0, mt = 0;

		for (int j = 0; j < v.size(); j++) {
			int mx = 2e9;
			for (int l = i + 1; l < k; l++) {
				if (v[j] == arr[l]) {
					mx = l;
					break;
				}
			}

			if (md < mx) {
				md = mx;
				mt = j;
			}
		}
		v[mt] = arr[i];
		ans++;
	}

	cout << ans;
	return 0;
}