#include <iostream>
#include <cmath>
using namespace std;

int arr[129][129];
int b, w;

void rep(int n, int x, int y)
{
	int c = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != c) {
				rep(n / 2, x, y);
				rep(n / 2, x + n / 2, y);
				rep(n / 2, x, y + n / 2);
				rep(n / 2, x + n / 2, y + n / 2);

				return;
			}
		}
	}
	if (c == 1) b++;
	else w++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	rep(n, 1, 1);
	cout << w << "\n" << b;
	return 0;
}