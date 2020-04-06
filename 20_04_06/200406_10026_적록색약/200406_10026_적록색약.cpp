#include <iostream>
using namespace std;
bool check[101][101];
bool echeck[101][101];

int n, ans, eans;
int aw, ew;

void show(int** w, int x, int y)
{
	aw = w[x][y];
	check[x][y] = true;
	if (x != 0 && w[x - 1][y] == aw && check[x - 1][y] == false) show(w, x - 1, y);
	if (x != n - 1 && w[x + 1][y] == aw && check[x + 1][y] == false) show(w, x + 1, y);
	if (y != 0 && w[x][y - 1] == aw && check[x][y - 1] == false) show(w, x, y - 1);
	if (y != n - 1 && w[x][y + 1] == aw && check[x][y + 1] == false) show(w, x, y + 1);
	return;
}

void eshow(int** w, int x, int y)
{
	ew = w[x][y];
	echeck[x][y] = true;
	if (x != 0 && w[x - 1][y] == ew && echeck[x - 1][y] == false) eshow(w, x - 1, y);
	if (x != n - 1 && w[x + 1][y] == ew && echeck[x + 1][y] == false) eshow(w, x + 1, y);
	if (y != 0 && w[x][y - 1] == ew && echeck[x][y - 1] == false) eshow(w, x, y - 1);
	if (y != n - 1 && w[x][y + 1] == ew && echeck[x][y + 1] == false) eshow(w, x, y + 1);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char w;
	cin >> n;
	int** num = new int* [n];
	for (int i = 0; i < n; i++) num[i] = new int[n];
	int** nume = new int* [n];
	for (int i = 0; i < n; i++) nume[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> w;
			if (w == 'R' || w == 'G') {
				if (w == 'R') num[i][j] = 1;
				else if (w == 'G') num[i][j] = 2;
				nume[i][j] = 1;
			}
			else if (w == 'B') {
				num[i][j] = 3;
				nume[i][j] = 2;
			}

		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				ans++;
				show(num, i, j);
			}
			if (echeck[i][j] == false) {
				eans++;
				eshow(nume, i, j);
			}
		}
	cout << ans << ' ' << eans;
	return 0;
}