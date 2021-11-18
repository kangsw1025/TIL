#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<long long, int> mp;
	long long sum = 0;

	for (int i = 1; i <= 2000000; i++) {
		sum += i;
		mp[sum] = i;
	}

	long long a, b;
	cin >> a >> b;

	if (!mp[a + b]) cout << "-1";
	else {
		int ans = 0;
		int idx = mp[a + b];
		while (a) {
			ans++;
			a -= min(a, (long long)idx);
			idx--;
		}

		cout << ans;
	}
	return 0;
}