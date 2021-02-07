#include <iostream>
using namespace std;

bool check[101];
bool ch[101][101];
int n;

void dfs(int x)
{
	check[x] = true;
	for (int i = 1; i <= n; i++)
		if (ch[x][i] == true && check[i] == false) dfs(i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, a, b, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ch[a][b] = true;
		ch[b][a] = true;
	}

	dfs(1);
	for (int i = 2; i <= n; i++)
		if (check[i] == true) cnt++;
	cout << cnt;
	return 0;
}