#include <iostream>
using namespace std;

int peo[15][15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int a, b;

	for (int i = 1; i <= 14; i++) peo[0][i] = i;
	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 14; j++)
			for (int k = 1; k <= j; k++)
				peo[i][j] += peo[i - 1][k];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << peo[a][b] << "\n";
	}
	return 0;
}