#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string st[251];

string sum(string a, string b) {

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() < b.length()) a += "0";

	string rst = "";
	int ch = 0;

	for (int i = 0; i < b.length(); i++) {
		int sum = a[i] - '0' + b[i] - '0';
		rst += (sum + ch) % 10 + '0';
		ch = (sum + ch) / 10;
	}
	if (ch) rst += "1";

	reverse(rst.begin(), rst.end());

	return rst;
}

void solve() {
	st[0] = "1";
	st[1] = "1";
	st[2] = "3";

	for (int i = 3; i <= 250; i++) {
		st[i] = sum(sum(st[i-2],st[i - 2]), st[i - 1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	int n;

	while (cin >> n) {
		cout << st[n]<<"\n";
	}
	return 0;
}