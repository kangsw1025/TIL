#include<iostream>
using namespace std;

int arr[11];

int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (arr[n]) return arr[n];
	arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
	return arr[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,num;
	cin >> n;
	while (n--) {
		cin >> num;
		cout << dp(num) << "\n";
	}
	return 0;
}