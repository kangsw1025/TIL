#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	map<int, pair<bool, int>> mp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]] = { false,i };
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int num = arr[i] + arr[j];
			if (mp.count(num)) {
				if (mp[num].second != i && mp[num].second != j)
					mp[num].first = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (mp[arr[i]].first) ans++;

	cout << ans;
	return 0;
}