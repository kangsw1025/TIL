#include<iostream>
using namespace std;

int arr[101][10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= 9; i++) arr[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][j + 1];
			else if (j == 9) arr[i][j] = arr[i - 1][j - 1];
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%1000000000;
		}
	}
	for (int i = 0; i < 10; i++) ans = (ans + arr[n][i])%1000000000;
	cout << ans;
	return 0;
}