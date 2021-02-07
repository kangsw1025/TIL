#include<iostream>
#include<algorithm>
using namespace std;

int arr[51], dp[51];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	fill(dp, dp + n, -1);
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
		for (int j = 0; j < n; j++)
			if (arr[i] > arr[j]) dp[i]++;

		while (1) {
			bool flag = false;

			for (int k = 0; k < n; k++) 
				if (i != k && dp[i] == dp[k]) {
					dp[i]++;
					flag = true;
				}
			
			if (!flag) break;
		}
	}

	for (int i = 0; i < n; i++) cout << dp[i] << ' ';
	return 0;
}