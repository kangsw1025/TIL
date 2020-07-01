#include<iostream>
using namespace std;

int arr[100001];
int ar[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, ans = -1001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ar[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (ar[i - 1] + arr[i] < arr[i]) ar[i] = arr[i];
		else ar[i] = ar[i - 1] + arr[i];

		if (ans < ar[i]) ans = ar[i];
	}
	if (ans > ar[0]) cout << ans;
	else cout << ar[0];
	return 0;
}