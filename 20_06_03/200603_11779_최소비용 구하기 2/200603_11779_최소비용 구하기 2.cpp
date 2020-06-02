#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 987654321
int n, m;
int arr[1001], p[1001], cnt[1001];
vector<pair<int, int>> v[1001];

void pf(int i)
{
	if(p[i]!=i) pf(p[i]);
	cout << i << ' ';
}

void show(int i) {
	cout << arr[i] << "\n";
	cout << cnt[i] << "\n";
	pf(i);
}

void solve(int s, int d)
{
	arr[s] = 0;
	cnt[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int dt = v[x][i].first;
			int pay = v[x][i].second;

			if (arr[dt] > arr[x] + pay) {
				arr[dt] = arr[x] + pay;
				p[dt] = x;
				cnt[dt] = cnt[x] + 1;
				q.push(dt);
			}
		}
	}

	show(d);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = INF;
		p[i] = i;
	}
	int s, d, p;
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> p;
		v[s].push_back(make_pair(d, p));
	}
	cin >> s >> d;
	solve(s, d);
	return 0;
}