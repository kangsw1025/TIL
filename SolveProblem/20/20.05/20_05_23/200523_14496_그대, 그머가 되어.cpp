#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321;
vector<int> v[1001];
int a, b, n, m;
int arr[1001];
bool ch[1001];

void solve()
{
	queue<int> q;
	q.push(a);
	ch[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (ch[v[x][i]] == false) {
				ch[v[x][i]] = true;
				q.push(v[x][i]);
			}
			if (arr[v[x][i]] > arr[x] + 1) arr[v[x][i]] = arr[x] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) arr[i] = INF;
	arr[a] = 0;
	int c, d;
	for (int i = 0; i < m; i++) {
		cin >> c >> d;
		v[c].push_back(d);
		v[d].push_back(c);
	}

	solve();

	if(arr[b] == 987654321) cout << -1;
	else cout << arr[b];
	
	return 0;
}