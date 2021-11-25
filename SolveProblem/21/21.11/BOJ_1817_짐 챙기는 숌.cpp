#include<iostream>
using namespace std;

int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, val, sum = 0, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> val;
		if (sum + val <= m) {
			sum += val;
		}
		else {
			sum = val;
			cnt++;
		}
	}
	if (sum) cnt++;
	cout << cnt;
	return 0;
}