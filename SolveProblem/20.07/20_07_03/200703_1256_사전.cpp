#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[201][201];
int check;

void reset() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = min(1000000000, dp[i - 1][j] + dp[i - 1][j - 1]);
		}
	}
}

void solve(int a, int z, string str) {
	if (check < 0) return;
	if (a == 0 && z == 0) {
		if (check == 0) cout << str;
		--check;
		return;
	}
	if (dp[a + z][z] <= check) {
		check -= dp[a + z][z];
		return;
	}
	if (a > 0) solve(a - 1, z, str + "a");
	if (z > 0) solve(a, z - 1, str + "z");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, z, n;
	cin >> a >> z >> n;
	check = n - 1;
	reset();
	if (dp[a + z][z] <= check) cout << -1;
	else solve(a, z, "");
	return 0;
}
