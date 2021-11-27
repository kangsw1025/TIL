#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int of = 0, ot = 0, tf = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "1/4") of++;
		else if (s == "1/2") ot++;
		else if (s == "3/4") tf++;
	}

	ans += ot / 2;
	ot = ot % 2 ? 1 : 0;

	if (tf) {
		ans += tf;
		of -= min(of, tf);
	}

	if (ot) {
		ans++;
		ot--;
		of -= min(of, 2);
	}

	ans += of / 4;
	if (of % 4) ans++;

	cout << ans;

	return 0;
}