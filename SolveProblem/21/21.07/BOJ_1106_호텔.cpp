#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1001];
vector<pair<int, int>> vec;

int solve(int cust, int city) {
	int Min = 2e9;
	int cost;

	if (cust <= 0) return 0;
	else if (dp[cust] > 0) return dp[cust];
	else {
		for (int i = 0; i < city; i++) {
			cost = solve(cust - vec[i].second, city) + vec[i].first;
			Min = min(Min, cost);
		}
		dp[cust] = Min;
		return Min;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, N;
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		int pay, cust;
		cin >> pay >> cust;
		vec.push_back({ pay, cust });
	}

	cout << solve(C, N);
	return 0;
}