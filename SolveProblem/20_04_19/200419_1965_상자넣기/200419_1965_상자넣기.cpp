#include <iostream>
using namespace std;

int arr[1001];
int d[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max, cnt= 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && max < d[j]) max = d[j];
		}
		d[i] = max + 1;
		if (d[i] > cnt) cnt = d[i];
	}
	cout << cnt;
	return 0;
}