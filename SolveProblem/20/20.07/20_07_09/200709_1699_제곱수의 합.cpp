#include<iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (arr[i] > arr[i - j * j] + 1 || arr[i] == 0)
				arr[i] = arr[i - j * j] + 1;
		}
	}
	cout << arr[n];
	return 0;
}