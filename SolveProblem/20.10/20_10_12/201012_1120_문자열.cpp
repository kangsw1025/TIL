#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int solve(string a, string b) {
	int ans = 2e9;

	for (int i = 0; i <= b.length() - a.length();i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) 
			if (a[j] != b[i + j]) cnt++;
		ans = min(ans, cnt);
	}
	return ans;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << solve(a, b);
	return 0;
}