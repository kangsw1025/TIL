#include<iostream>
#include<algorithm>
using namespace std;

int solve(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) return 0;
	if (a == 0 && b == 0) return 1;
	if (b == 0 && c == 0) return 1;
	if (c == 0 && a == 0) return 1;

	return max(a, max(b, c));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	cout << a / 3 + b / 3 + c / 3 + solve(a % 3, b % 3, c % 3);
	return 0;
}