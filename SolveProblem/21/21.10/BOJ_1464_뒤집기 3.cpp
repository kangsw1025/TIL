#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	string ss = s.substr(0, 1);
	for (int i = 1; i < s.length(); i++) {
		if (ss[i - 1] < s[i]) ss = s[i] + ss;
		else ss = ss + s[i];
	}
	reverse(ss.begin(), ss.end());
	cout << ss;
	return 0;
}