#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int sdp[1001];
int bdp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, Max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		int small = 0;
		int big = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (small < sdp[j]) small = sdp[j];
			}
			if (arr[n - i + 1] > arr[n - j + 1]) {
				if (big < bdp[n - j + 1]) big = bdp[n - j + 1];
			}
		}
		sdp[i] = small + 1;
		bdp[n - i + 1] = big + 1;
	}
	for (int i = 1; i <= n; i++)
		Max = max(Max, sdp[i] + bdp[i] - 1);
	cout << Max;
}