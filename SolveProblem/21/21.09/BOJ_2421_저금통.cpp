#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool prime[1000000];
int dp[1000][1000];

void sosu() {
	prime[0] = true;
	prime[1] = true;
	for(int i=2;i<=1000;i++)
		if (!prime[i])
			for (int j = 2; i * j <= 1000000; j++)
				prime[i * j] = true;
}

bool isprime(int l, int r) {
	int r2 = r;
	while (r2) {
		r2 /= 10;
		l *= 10;
	}
	int rst = l + r;
	if (prime[rst]) return false;
	return true;
}

int solve(int left, int right) {
	if (left == 0 || right == 0) return 0;

	int& ret = dp[left][right];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, max(solve(left - 1, right), solve(left, right - 1)));
	
	if (isprime(left, right)) ret++;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sosu();

	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 0;
	cout << solve(n, n);
	return 0;
}