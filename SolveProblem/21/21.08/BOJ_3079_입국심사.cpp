#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	
	long long left = 0, right = 1e18+1;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += (mid / arr[i]);
			if (cnt >= p) break;
		}

		if (cnt >= p) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;

	return 0; 
}