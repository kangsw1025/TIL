#include<iostream>
using namespace std;

int arr[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 30; i++) {
		arr[i][1] = 1;
		arr[i][i] = 1;
	}

	for (int i = 3; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	int R, C, W, sum = 0, idx = 1;
	cin >> R >> C >> W;

	for (int i = R; i < R + W; i++) {
		for (int j = C; j < C + idx; j++)
			sum += arr[i][j];
		idx++;
	}
	cout << sum;
	return 0;
}