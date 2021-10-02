#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string s[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string st;
	cin >> st;
	cout << st;

	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);

	int cnt = 0;

	while (m--) {
		string st;
		cin >> st;
		for (int i = 0; i < n; i++) {
			if (st[0] == s[i][0]) {
				string subs = s[i].substr(0, st.length());
				if (st == subs) {
					cnt++;
					break;
				}
			}
			else if (st[0] < s[i][0]) break;
		}
	}
	cout << cnt;
	return 0;
}