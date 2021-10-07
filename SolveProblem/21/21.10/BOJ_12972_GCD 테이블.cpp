#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> arr,ans;
map<int, int> mp;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int val;
		cin >> val;
		mp[val]++;
		arr.push_back(val);
	}

	sort(arr.begin(), arr.end());

	int idx = 0, cnt = n * n;

	ans.push_back(arr[n * n - 1]);
	idx++;
	cnt--;
	mp[ans[0]]--;

	if (mp[ans[0]] == 0) mp.erase(ans[0]);

	while (!mp.empty()) {
		int x = mp.rbegin()->first;
		mp[x]--;
		if (mp[x] == 0) mp.erase(x);

		for (int i = 0; i < idx; i++) {
			int gc = gcd(ans[i], x);
			mp[gc] -= 2;
			if (mp[gc] == 0) mp.erase(gc);
			cnt -= 2;
		}
		ans.push_back(x);
		idx++;
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	return 0;
}