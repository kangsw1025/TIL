#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string name;
	map<string, int> mp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		if (mp.find(name) == mp.end()) mp[name] = 1;
		else mp[name]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> name;
		mp[name]++;
	}
	for (auto itr = mp.begin(); itr != mp.end(); itr++)
		if (itr->second % 2) cout << itr->first;
	return 0;
}