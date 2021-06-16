#include<iostream>
using namespace std;

int arr[101][101][4];
// 0 1 -> 0-0 0-1
// 2 3 -> 1-0 1-1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	arr[2][0][0] = 1;
	arr[2][0][1] = 1;
	arr[2][0][2] = 1;
	arr[2][1][3] = 1;

	for (int i = 3; i <= 100; i++)
		for (int j = 0; j <= i - 1; j++) {
			arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j][1];
			arr[i][j][1] = arr[i - 1][j][0] + arr[i - 1][j - 1][1];
			arr[i][j][2] = arr[i - 1][j][2] + arr[i - 1][j][3];
			arr[i][j][3] = arr[i - 1][j][2] + arr[i - 1][j - 1][3];
		}

	int n;
	cin >> n;
	while (n--) {
		int a, b, rst = 0;
		cin >> a >> b;
		for (int i = 0; i < 4; i++) rst += arr[a][b][i];
		cout << rst << "\n";
	}

	return 0;
}