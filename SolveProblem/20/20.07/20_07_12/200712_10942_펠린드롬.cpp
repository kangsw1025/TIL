#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[2001];
bool c[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m,a,b;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) c[i][i] = true;
	for (int i = 1; i + 1 <= n; i++) 
		if (arr[i] == arr[i + 1]) c[i][i + 1] = true;
	
	for (int j = 2; j <= n; j++) {
		for (int i = 1; i + j <= n; i++) {
			int e = i + j;
			if (c[i + 1][e - 1] && arr[i] == arr[e]) c[i][e] = true;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << int(c[a][b]) << "\n";
	}

	return 0;
}