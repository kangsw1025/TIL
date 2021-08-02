#include<iostream>
#include<stack>
using namespace std;

stack<int> st[7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p, ans = 0;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int line, plet;
		cin >> line >> plet;
		if (st[line].empty()) {
			ans++;
			st[line].push(plet);
		}
		else {
			if (st[line].top() < plet) {
				ans++;
				st[line].push(plet);
			}
			else {
				while (!st[line].empty() && st[line].top() > plet) {
					st[line].pop();
					ans++;
				}

				if (st[line].empty() || st[line].top() < plet) {
					st[line].push(plet);
					ans++;
				}
				
			}
		}
	}
	cout << ans;
	return 0;
}