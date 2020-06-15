#include<iostream>
#include<queue>
using namespace std;

int n, k;
int money[11];

int solve() {
	int cnt = k / money[0];
	for (int i = n - 1; i >= 0; i--) {
		if (k >= money[i]) {
			cnt = cnt + (k / money[i]) * (1 - money[i]);
			k %= money[i];
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> money[i];

	cout<<solve();
	return 0;
}