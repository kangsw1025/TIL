#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<long long, pair<int, int>> lii;

int p[100001];
lii pa[100001];

int find_p(int n) {
	if (p[n] == n) return n;
	else find_p(p[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		int a, b, c;
		cin >> a >> b >> c;
		pa[i] = { a,{b,c} };
	}

	priority_queue < lii, vector < lii >, greater<lii>> q;

	for (int i = 1; i <= n; i++) {
		long long x1 = pa[i].first;
		long long y1 = pa[i].second.first;
		long long z1 = pa[i].second.second;
		for (int j = i + 1; j <= n; j++) {
			long long x2 = pa[j].first;
			long long y2 = pa[j].second.first;
			long long z2 = pa[j].second.second;

			long long dst = min(abs(x2 - x1), min(abs(y2 - y1), abs(z2 - z1)));

			q.push({ dst,{i,j} });
		}
	}

	long long ans = 0;

	while (!q.empty()) {
		long long dst = q.top().first;
		int n = q.top().second.first;
		int m = q.top().second.second;
		q.pop();

		int np = find_p(n);
		int mp = find_p(m);
		if (np == mp) continue;

		ans += dst;
		p[np] = mp;
	}

	cout << ans;
	return 0;
}