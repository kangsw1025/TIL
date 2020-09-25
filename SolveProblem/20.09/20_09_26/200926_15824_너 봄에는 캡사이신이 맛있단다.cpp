#include<iostream>
#include<algorithm>
using namespace std;

#define Mod 1000000007
long long arr[300001], mul[3000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	mul[0] = 1;
	for (int i = 1; i <= n; i++)
		mul[i] = (mul[i - 1] * 2) % Mod;
	for (int i = 1; i <= n; i++)
		ans = (ans + arr[i] * (-mul[n - i] + mul[i-1])) % Mod;
	cout << ans;
	return 0;
}