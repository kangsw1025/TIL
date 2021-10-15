#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n + 1);

	int zero = 0;
	for(int i=0;i<=n;i++)
		if (arr[i] == 0) {
			zero = i;
			break;
		}
	
	int ans = 0;

	for (int i = 0; i < zero; i += m)
		ans += abs(arr[i]) * 2;
	for (int i = n; i > zero; i -= m)
		ans += arr[i] * 2;

	ans -= (abs(arr[0]) > abs(arr[n]) ? abs(arr[0]) : abs(arr[n]));
	cout << ans;
	return 0;
}