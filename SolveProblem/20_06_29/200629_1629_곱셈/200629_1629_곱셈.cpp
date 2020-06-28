#include<iostream>
using namespace std;

long long solve(long long a, long long b, long long c) {
	if (b == 1) return a;
	else {
		long long ans = solve(a, b / 2, c);

		if (b % 2) return ans * ans % c * a % c;
		else return ans * ans % c;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	
	cout << solve(a % c, b, c);
	return 0;
}