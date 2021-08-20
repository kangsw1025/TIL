#include<iostream>
using namespace std;

int n, arr[1001][2][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	arr[1][0][0] = 1;
	arr[1][1][0] = 1;
	arr[1][0][1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i][0][0] = (arr[i - 1][0][0] + arr[i - 1][0][1] + arr[i - 1][0][2]) % 1000000;
		arr[i][0][1] = arr[i - 1][0][0];
		arr[i][0][2] = arr[i - 1][0][1];
		arr[i][1][0] = (arr[i - 1][0][0] + arr[i - 1][0][1] + arr[i - 1][0][2]
			+ arr[i - 1][1][0] + arr[i - 1][1][1] + arr[i - 1][1][2]) % 1000000;
		arr[i][1][1] = arr[i - 1][1][0];
		arr[i][1][2] = arr[i - 1][1][1];
	}

	int ans = (arr[n][0][0] + arr[n][0][1] + arr[n][0][2] + arr[n][1][0] + arr[n][1][1] + arr[n][1][2]) % 1000000;
	cout << ans;

	return 0;
}