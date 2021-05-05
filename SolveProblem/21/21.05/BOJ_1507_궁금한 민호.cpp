#include<iostream>
#include<cstring>
using namespace std;

int arr[21][21];
bool cache[21][21];
int rst;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	
	memset(cache, true, sizeof(cache));

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || i == k) continue;
				else if (arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << -1;
					return 0;
				}
				else if (arr[i][j] == arr[i][k] + arr[k][j]) cache[i][j] = false;
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (cache[i][j]) rst += arr[i][j];

	cout << rst / 2;
	return 0;
}