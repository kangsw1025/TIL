#include<iostream>
using namespace std;

long long A, B;

long long solve(long long num) {
	num++;
	long long n = num, l = 1, r = 0;
	while (n) {
		if (num & l) r += num % l + (num - num % (l * 2)) / 2;
		else r += (num - num % l) / 2;
		l <<= 1;
		n >>= 1;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;
	cout << solve(B) - solve(A - 1);

	return 0;
}