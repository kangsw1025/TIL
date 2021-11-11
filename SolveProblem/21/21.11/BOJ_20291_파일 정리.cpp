#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> mp;

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		string name = "";
		bool on = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				on = true;
				continue;
			}

			if (on) {
				name += s[i];
			}
		}

		mp[name]++;
	}

	for (auto it : mp) {
		cout << it.first << ' ' << it.second << "\n";
	}
	return 0;
}