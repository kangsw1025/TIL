#include<iostream>
#include<algorithm>
using namespace std;

#define INF 987654321
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int i = 0, j = 0;
	long long sum = 0;
	sum = arr[0];
	int ans = INF;
	while (i <= j && j<n && i<n) {
		if (sum >= m) {
			ans = min(ans, j - i + 1);
			if (i == j) {
				i++;
				j++;
				sum = arr[i];
			}
			else {
				sum -= arr[i];
				i++;
			}
		}
		else {
			j++;
			if(j<n)	sum += arr[j];
		}
	}
	if (ans == INF) cout << 0;
	else cout << ans;
	return 0;
}