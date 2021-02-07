#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() > b.length()) b += '0';
	while (a.length() < b.length()) a += '0';

	string ans = "";
	int carry = 0;

	for (int i = 0; i < a.length(); i++) {
		ans += '0' + (a[i] - '0' + b[i] - '0' + carry) % 2;
		carry = (a[i] - '0' + b[i] - '0' + carry) / 2;
	}
	if (carry) ans += '1';
	reverse(ans.begin(), ans.end());
	bool first = true;
	for (int i = 0; i < ans.length(); i++) {
		if (first) {
			if (ans[i] == '0') continue;
			else if (ans[i] == '1') first = false;
		}
		cout << ans[i];
	}
	if (first) cout << '0';
	return 0;
}