#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 999999
vector<pair<int,int>> v[1001];
int n, b, e;



vector<int> solve(int s, int d)
{
	vector<int> vec(d, INF);
	vec[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push(make_pair(0,s));

	while (!q.empty()) {
		int x = q.top().second;
		int pay = q.top().first;
		q.pop();

		if (vec[x] < pay) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].second;
			int co = v[x][i].first + pay;;

			if (vec[nx] > co) {
				vec[nx] = co;
				q.push(make_pair(co, nx));
			}
		}
	}
	return vec;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b >> e;
	int s, d, p;

	for (int i = 0; i < b; i++) {
		cin >> s >> d >> p;
		v[s].push_back(make_pair(p, d));
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		vector<int> t = solve(i, n + 1);
		vector<int> t2 = solve(e, n + 1);

		ans = max(ans, t[e] + t2[i]);
	}
	cout << ans;
	return 0;
}