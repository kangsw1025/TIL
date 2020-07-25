#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, cnt;
vector<vector<int>> vec;
int check[1001];
int there[1001];

int dfs(int h)
{
	if (check[h]) return 0;
	check[h] = 1;

	for (int i = 0; i < vec[h].size(); i++) {
		int t = vec[h][i];
		if (!there[t] || dfs(there[t])) {
			there[t] = h;
			return 1;
		}
	}
	return 0;
}

void BM()
{
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i)) cnt++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vec.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			vec[i].push_back(b);
		}
	}

	BM();
	cout << cnt;
	return 0;
}