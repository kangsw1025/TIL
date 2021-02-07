#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve(string a, string b) {
	int carry = 0;
	string ans = "";
	for (int i = 0; i < a.length(); i++) {
		char num = ((a[i] - '0' + b[i] - '0' + carry) % 10) + '0';
		ans += num;
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	if (carry == 1) ans += '1';
	reverse(ans.begin(), ans.end());
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.length() > b.length()) b += '0';
	while (a.length() < b.length()) a += '0';
	solve(a, b);
	return 0;
}