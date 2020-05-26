#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 9999999
vector<pair<int, int>> vec[201];
int arr[201][201];
int ans[201][201];
int n, m;

int find(int i, int j)
{
	if (ans[i][j] == i) return j;
	else return find(i, ans[i][j]);
}

void solve(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, s));
	arr[s][s] = 0;
	ans[s][s] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		int p = q.top().first;
		q.pop();

		for (int i = 0; i < vec[x].size(); i++) {
			int pay = vec[x][i].first + p;
			int next = vec[x][i].second;

			if (arr[s][next] > pay) {
				ans[s][next] = x;
				arr[s][next] = pay;
				q.push(make_pair(pay, next));
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) arr[i][j] = INF;
	
	int s, d, p;
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> p;
		vec[s].push_back(make_pair(p, d));
		vec[d].push_back(make_pair(p, s));
	}

	for (int i = 1; i <= n; i++) {
		solve(i);
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << find(i, j) << ' ';
		}
		cout << "\n";
	}
	return 0;
}