#include<iostream>
using namespace std;

int arr[9];
int ans[9];
bool ch[9];
int a, b;

void solve(int n) {
	if (n == b) {
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << "\n";
	}
	else {
		for (int i = 1; i <= a; i++) {
				ans[n] = i;
				solve(n + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i <= a; i++) arr[i] = i;
	for (int i = 1; i <= a; i++) {
		ans[0] = i;
		solve(1);
	}
	return 0;
}