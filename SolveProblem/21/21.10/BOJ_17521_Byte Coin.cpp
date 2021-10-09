#include<iostream>
#include<algorithm>
using namespace std;

int arr[16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long w, coin = 0;

	cin >> n >> w;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] < arr[i]) {
			long long c = w / arr[i - 1];
			w += (arr[i] - arr[i - 1]) * c;
		}
	}

	cout << w;

	return 0;
}