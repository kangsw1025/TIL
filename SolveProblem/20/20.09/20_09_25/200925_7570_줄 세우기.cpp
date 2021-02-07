#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];

int main() {
	int n;
	cin >> n;

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr[num] = arr[num-1] + 1;
		ans = max(ans, arr[num]);
	}
	cout << n - ans;
	return 0;
}