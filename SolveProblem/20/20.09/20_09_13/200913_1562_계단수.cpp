#include<iostream>
#include<cstring>
using namespace std;

int n;
int arr[10][101][1 << 10];

int solve(int num, int length, int number) {
	if (length == n)
		return number == (1 << 10) - 1 ? 1 : 0;

	int& result = arr[num][length][number];
	if (result != -1) return result;

	result = 0;
	if (num - 1 >= 0) result += solve(num - 1, length + 1, number | 1 << (num - 1));
	if (num + 1 < 10) result += solve(num + 1, length + 1, number | 1 << (num + 1));
	result %= 1000000000;
	return result;
}

int main() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		memset(arr, -1, sizeof(arr));
		ans += solve(i, 1, 1 << i);
		ans %= 1000000000;
	}
	cout << ans;
	return 0;
}