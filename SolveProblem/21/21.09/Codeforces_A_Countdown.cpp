#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, cnt = 0;
		string s;
		cin >> n;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] !='0') {
				if (i != s.length() - 1) cnt++;

				cnt += s[i] - '0';
			}

		}

		cout << cnt << "\n";
	}
	return 0;
}