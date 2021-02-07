#include<iostream>
using namespace std;

long long dp[31][31];

long long solve(int w, int h) {
	if (dp[w][h]) return dp[w][h];

	if (w == 0) return 1;

	dp[w][h] = solve(w - 1, h + 1);
	if (h > 0) dp[w][h] += solve(w, h - 1);

	return dp[w][h];
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << solve(n,0)<<"\n";
	}
	return 0;
}