#include<iostream>
using namespace std;

int arr[101][101][101];
bool check[101][101][101];

int solve(int a, int b, int c) {
	if (check[a][b][c]) return arr[a][b][c];
	else {
		check[a][b][c] = true;
		if (a <= 50 || b <= 50 || c <= 50) return arr[a][b][c] = 1;
		else if (a > 70 || b > 70 || c > 70) return arr[a][b][c] = solve(70, 70, 70);
		else if (a < b && b < c) return arr[a][b][c] = (solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c));
		else return arr[a][b][c] = (solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		else cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a+50, b+50, c+50) << "\n";
	}
	return 0;
}