#include<iostream>
#include<vector>
using namespace std;

int n, k, s;
int arr[401][401];

void solve() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++) 
				if (i == j || j == k || k == i) continue;
				else {
					if (arr[j][k] == 0) {
						if (arr[j][i] == 1 && arr[i][k] == 1) arr[j][k] = 1;
						else if (arr[j][i] == -1 && arr[i][k] == -1) arr[j][k] = -1;
					}
				}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		arr[a][b] = -1;
		arr[b][a] = 1;
	}
	solve();
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
	return 0;
}