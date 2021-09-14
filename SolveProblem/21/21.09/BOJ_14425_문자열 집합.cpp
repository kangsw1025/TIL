#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, bool> mp;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = true;
	}

	int ans = 0;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (mp[s]) ans++;
	}

	cout << ans;
	return 0;
}