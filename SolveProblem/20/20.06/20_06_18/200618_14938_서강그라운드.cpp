#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 987654321
//priority_queue<int, vector<int>, greater<int>> q;
queue<int> q;
vector<pair<int, int>> vec[101];
int dis[101][101], item[101];
int it_n, all, way;

void first_set() {
	for (int i = 1; i <= it_n; i++)
		for (int j = 1; j <= it_n; j++) dis[i][j] = INF;
}

int solve(int s) {
	
	dis[s][s] = 0;
	for(int i=0;i<vec[s].size();i++)
		q.push(s);

	while (!q.empty()) {
		int w = q.front();
		q.pop();

		for (int i = 0; i < vec[w].size(); i++) {
			int next = vec[w][i].second;
			int price = vec[w][i].first;

			if (dis[s][next] > dis[s][w] + price) {
				dis[s][next] = dis[s][w] + price;
				q.push(next);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= it_n; i++)
		if (dis[s][i] <= all) ans += item[i];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s, d, p;
	cin >> it_n >> all >> way;
	first_set();
	for (int i = 1; i <= it_n; i++) cin >> item[i];

	for (int i = 0; i < way; i++) {
		cin >> s >> d >> p;
		vec[s].push_back(make_pair(p, d));
		vec[d].push_back(make_pair(p, s));
	}

	int ans = 0;
	for (int i = 1; i <= it_n; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans;
	return 0;
}