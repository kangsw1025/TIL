#include <iostream>
using namespace std;

int arr[501][501];
int check[501][501];
bool ch[501][501];
int a, b;

int dfs(int x, int y)
{
	int vec_x[4] = { 1,0,-1,0 };
	int vec_y[4] = { 0,1,0,-1 };
	
	if (x == a && y == b) return 1;
	if (ch[x][y]) return check[x][y];
	ch[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + vec_x[i];
		int next_y = y + vec_y[i];
		if (next_x > 0 && next_x <= a && next_y > 0 && next_y <= b)
			if(arr[next_x][next_y] < arr[x][y])
				check[x][y] += dfs(next_x, next_y);
	}
	return check[x][y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++) cin >> arr[i][j];

	cout << dfs(1,1);
	return 0;
}