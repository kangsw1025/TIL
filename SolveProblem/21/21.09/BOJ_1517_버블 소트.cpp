#include<iostream>
using namespace std;

const int MAX = 5e5 + 1;
int arr[MAX], arr2[MAX];

long long solve(int start, int end) {
	if (start == end) return 0;

	int mid = (start + end) / 2;

	long long rst = solve(start, mid) + solve(mid + 1, end);

	int i = start, j = mid + 1, idx = 0;

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || arr[i] <= arr[j]))
			arr2[idx++] = arr[i++];
		else {
			rst += (mid - i + 1) * 1LL;
			arr2[idx++] = arr[j++];
		}
	}

	for (int i = start; i <= end; i++)
		arr[i] = arr2[i - start];
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << solve(0, n - 1);
	return 0;
}