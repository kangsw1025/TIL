#include <iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		if (arr[i] * (n-i) > max) max = arr[i] * (n-i);

	cout << max;
	return 0;
}