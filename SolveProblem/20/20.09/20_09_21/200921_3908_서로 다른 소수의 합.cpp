#include<iostream>
#include<vector>
using namespace std;

int dp[1121][15];
bool check[1121];
vector<int> vec;

void sosu() {
	for (int i = 2; i <= 1120; i++) {
		if (!check[i]) {
			vec.push_back(i);
			for (int j = 2; i * j <= 1120; j++) check[i * j] = true;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i <vec.size(); i++) {
		for (int j =1120; j >= vec[i]; j--) {
			for (int k = 1; k <=14; k++)
				dp[j][k] += dp[j - vec[i]][k - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sosu();
	
	int T, n, k;
	cin >> T;
	
	while (T--) {
		cin >> n >> k;
		cout << dp[n][k]<<"\n";
	}
	return 0;
}