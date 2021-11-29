#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

void solve(string s) {
	string rst = "";
	int len = s.length();
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i += 3) {
		string n = "";
		for (int j = i; j < min(i + 3, len); j++) {
			n += s[j];
		}

		int sum = 0;
		for (int j = 0; j < n.length(); j++) {
			if (n[j] == '1') sum += pow(2, j);
		}

		rst += '0' + sum;
	}

	reverse(rst.begin(), rst.end());
	cout << rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	solve(s);
	return 0;
}