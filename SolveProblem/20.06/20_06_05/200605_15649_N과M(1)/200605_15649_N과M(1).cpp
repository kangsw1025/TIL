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
			if (ch[i] == false) {
				ch[i] = true;
				ans[n] = i;
				solve(n + 1);
				ch[i] = false;
			}
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
		ch[i] = true;
		ans[0] = i;
		solve(1);
		ch[i] = false;
	}
	return 0;
}