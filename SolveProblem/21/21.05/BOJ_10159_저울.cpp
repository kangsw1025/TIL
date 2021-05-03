#include<iostream>
#include<vector>
using namespace std;

bool adj[101][101], comp[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, T;
	cin >> n >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		
		adj[a][b] = true;
	}

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) comp[i][j] = true;
			else if (adj[i][j]) comp[i][j] = true;
		}

	for(int k=1;k<=n;k++) 
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++) 
				if (!comp[i][j]) 
					if (comp[i][k] && comp[k][j]) comp[i][j] = true;
				
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (comp[i][j] || comp[j][i]) cnt++;

		cout << n - cnt << "\n";
	}

	return 0;
}