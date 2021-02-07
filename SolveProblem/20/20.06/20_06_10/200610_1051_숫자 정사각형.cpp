#include<iostream>
#include<algorithm>
using namespace std;

char arr[51][51];
int n_x[3] = { 0,1,1 };
int n_y[3] = { 1,0,1 };
int x, y;

int solve(int w, int h)
{
	int size = 1;
	for (int i = 1; i < min(x - w, y - h); i++) {
		int nx = w + i;
		int ny = h + i;
		if (nx < x && ny < y) {
			if (arr[w][h] == arr[w + i][h] && arr[w][h] == arr[w][h + i] && arr[w][h] == arr[w + i][h + i])
				size = (1 + i) * (1 + i);
		}

	}
	return size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];

	int ans = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			ans = max(ans, solve(i, j));

	cout << ans;
	return 0;
}
