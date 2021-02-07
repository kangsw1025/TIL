#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[501];
int dp[501];
vector<int> vec[501];

int solve(int num) {

	if (dp[num]) return dp[num];

	if (!vec[num].size()) return arr[num];
	else {
		int M = 0;
		for (int i = 0; i < vec[num].size(); i++)
			M = max(M, solve(vec[num][i]));
		dp[num] = M + arr[num];
		return M + arr[num];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (1) {
			cin >> num;
			if (num == -1) break;
			vec[i].push_back(num);
		}
	}

	for (int i = 1; i <= n; i++) cout << solve(i) << "\n";
	return 0;
}