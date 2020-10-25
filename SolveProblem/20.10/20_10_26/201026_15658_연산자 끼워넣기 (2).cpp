#include<iostream>
using namespace std;

long long big = -2e9, small = 2e9;
int arr[101];
int have[4];
int n;

void solve(int sum, int now) {
	if (now == n) {
		if (sum > big) big = sum;
		if (sum < small) small = sum;
	}
	else {
		if (have[0]) {
			have[0]--;
			solve(sum + arr[now], now + 1);
			have[0]++;
		}
		if (have[1]) {
			have[1]--;
			solve(sum - arr[now], now + 1);
			have[1]++;
		}
		if (have[2]) {
			have[2]--;
			solve(sum * arr[now], now + 1);
			have[2]++;
		}
		if (have[3]) {
			have[3]--;
			solve(sum / arr[now], now + 1);
			have[3]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> have[i];

	solve(arr[0],1);
	cout << big << "\n" << small;
	return 0;
}
