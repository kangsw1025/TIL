#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 987654321;

int arr[101][101];
int ans[101];
vector<int> vec[101];
bool v[101];
int n, m;

void set(int k)
{
	for (int i = 1; i <= k; i++) {
		v[i] = false;
		for (int j = 1; j <= k; j++) arr[i][j] = INF;
	}
	
}

void solve(int k)
{
	arr[k][k] = 0;
	v[k] = true;
	queue<int> q;
	q.push(k);
	while (!q.empty()) {
		int z = q.front();
		q.pop();
		for (int i = 0; i < vec[z].size(); i++) {
			if (v[vec[z][i]] == false) {
				arr[k][vec[z][i]] = arr[k][z] + 1;
				q.push(vec[z][i]);
				v[vec[z][i]] = true;
			}
		}
	}
}

int count(int num)
{
	int su = 0;
	for (int i = 1; i <= n; i++)
		su += arr[num][i];
	return su;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());

	int answer = INF;
	for (int i = 1; i <= n; i++) {
		set(n);
		solve(i);
		ans[i] = count(i);
		if (answer > ans[i]) answer = ans[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == answer) {
			cout << i;
			break;
		}
	}
	return 0;
}