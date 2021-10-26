#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	if (n > x || n * 26 < x) cout << "!";
	else {
		string ans = "";
		while (n) {
			int val = min(x - n, 25);
			ans += 'A' + val;
			n--;
			x -= val + 1;
		}
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	return 0;
}