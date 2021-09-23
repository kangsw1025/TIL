#include<iostream>
using namespace std;

bool dp[1000001];

void init() {
	dp[0] = true;
	dp[1] = true;

	for (int i = 2; i <= 1000; i++)
		dp[i * i] = true;

	for (int i = 2; i <= 1000000; i++) {
		if (dp[i] == false) {
			for (int j = 1; j * j + i <= 1000000; j++) dp[i + j * j] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		if (dp[n]) cout << "koosaga\n";
		else cout << "cubelover\n";
	}
	return 0;
}