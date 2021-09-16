#include<iostream>
#include<cmath>
using namespace std;

int arr[1001], dp[1001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 3; i <= 1000; i++)
		for (int j = 2; j < i; j++)
			for(int k=2;k<=j;k++)
				if (i % k == 0 && j % k == 0) {
					arr[i]++;
					break;
				}
	
	dp[1] = 3;
	for (int i = 2; i <= 1000; i++)
		dp[i] = dp[i - 1] + (i -1 - arr[i]) * 2;

	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}