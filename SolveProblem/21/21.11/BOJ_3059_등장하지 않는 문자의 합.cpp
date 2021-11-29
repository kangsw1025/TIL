#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int sum = 2015;

bool use[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(use, false, sizeof(use));

		int ans = sum;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (use[c - 'A'] == false) {
				ans -= c;
				use[c - 'A'] = true;
			}
		}
		cout << ans << "\n";
	}
}