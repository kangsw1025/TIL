#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

struct planet {
	int id, x, y, z;
	int dst(const planet& pl) {
		return min({ abs(x - pl.x), abs(y - pl.y), abs(z - pl.z) });
	}
};

struct edge {
	int u, v, w;
	bool operator < (const edge& e) const {
		return w < e.w;
	}
};

planet pl[100001];
int p[100001];

int fi(int n) {
	if (p[n] == n) return n;
	return p[n] = fi(p[n]);
}

bool merge(int l, int r) {
	l = fi(l);
	r = fi(r);
	if (l == r) return false;
	p[r] = l;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pl[i].x >> pl[i].y >> pl[i].z;
		pl[i].id = i;
		p[i] = i;
	}
	
	vector<edge> e;
	sort(pl, pl + n, [](planet& a, planet& b) -> bool { return a.x < b.x; });
	for (int i = 1; i < n; i++) e.push_back({ pl[i - 1].id, pl[i].id, pl[i - 1].dst(pl[i]) });
	sort(pl, pl + n, [](planet& a, planet& b) -> bool { return a.y < b.y; });
	for (int i = 1; i < n; i++) e.push_back({ pl[i - 1].id, pl[i].id, pl[i - 1].dst(pl[i]) });
	sort(pl, pl + n, [](planet& a, planet& b) -> bool { return a.z < b.z; });
	for (int i = 1; i < n; i++) e.push_back({ pl[i - 1].id, pl[i].id, pl[i - 1].dst(pl[i]) });
	
	sort(e.begin(), e.end());

	long long ans = 0;
	for (auto& au : e) {
		if (merge(au.u, au.v)) ans += au.w;
	}

	cout << ans;

	return 0;
}