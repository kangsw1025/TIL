#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int n;
double ans;
int par[101];
pair<float, float> arr[101];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> q;

int parent(int x) {
	if (par[x] == x) return x;
	return parent(par[x]);
}

void join(int u, int v) {
	int up = parent(u);
	int vp = parent(v);

	par[up] = vp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout<<fixed;
	cout.precision(2);

	cin >> n;

	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		arr[i] = { x,y };
	}

	for(int i=1;i<n;i++)
		for (int j = i + 1; j <= n; j++) {
			double dst = sqrt(pow((arr[i].first - arr[j].first), 2) + pow((arr[i].second - arr[j].second), 2));
			q.push({ dst,{i,j} });
		}

	while (!q.empty()) {
		double dst = q.top().first;
		int u = q.top().second.first;
		int v = q.top().second.second;
		q.pop();

		if (parent(u) != parent(v)) {
			join(u, v);
			ans += dst;
		}
	}

	cout << ans;
	return 0;
}