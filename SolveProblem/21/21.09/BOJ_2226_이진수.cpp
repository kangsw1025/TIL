#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string sum(string z, string o) {
	string rst = "";

	while (z.length() > o.length()) {
		o = '0' + o;
	}

	while (z.length() < o.length()) {
		z = '0' + z;
	}

	int carry = 0;

	for (int i = z.length() - 1; i >= 0; i--) {
		int sum = o[i] - '0' + z[i] - '0' + carry;
		rst += sum % 10 + '0';
		carry = sum / 10;
	}
	if (carry) rst += '1';

	reverse(rst.begin(), rst.end());
	return rst;
}

string m_one(string s) {
	if (s[s.length() - 1] == '0') {
		s[s.length() - 2]--;
		s[s.length() - 1] = '9';
	}
	else s[s.length() - 1]--;
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string zero = "0", one = "1", tmp_zero, tmp_one;

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		string tmp_zero, tmp_one;
		if (i % 2) tmp_zero = m_one(sum(zero,one));
		else tmp_zero = sum(zero,one);

		tmp_one = sum(zero,one);
		zero = tmp_zero;
		one = tmp_one;
	}
	cout << zero;
	return 0;
}