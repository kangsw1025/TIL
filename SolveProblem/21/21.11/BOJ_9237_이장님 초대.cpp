#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1, cmp);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, i + arr[i]);
	}
	cout << ans + 1;
	return 0;
}