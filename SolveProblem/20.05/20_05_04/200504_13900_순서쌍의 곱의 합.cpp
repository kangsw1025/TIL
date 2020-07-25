#include<iostream>
using namespace std;

int arr[100001];
int n;
long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i];
	}
	ans = ans * ans;
	for (int i = 0; i < n; i++) ans -= arr[i] * arr[i];
	cout << ans / 2;
	return 0;
}