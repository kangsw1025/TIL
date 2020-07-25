#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 9999999;
int n, m, k, x;
vector<int> v[300001];
int arr[300001];
bool c[300001];

void solve()
{
	queue<int> q;
	q.push(x);
	c[x] = true;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 0; i < v[num].size(); i++) {
			if (c[v[num][i]] == false) {
				c[v[num][i]] = true;
				q.push(v[num][i]);
			}
			if (arr[v[num][i]] > arr[num] + 1) arr[v[num][i]] = arr[num] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k >> x;

	for (int i = 1; i <= n; i++) arr[i] = MAX;
	arr[x] = 0;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	solve();
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == k) {
			check = true;
			break;
		}
	}
	if (check == false) cout << -1;
	else {
		for (int i = 1; i <= n; i++) if (arr[i] == k) cout << i << "\n";
	}
	return 0;
}