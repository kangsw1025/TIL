#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

int T;
vector<pair<long long, long long>> v;
map<long long, int> mp;
int arr[2501];
char op[4] = { ' ','+','-','*' };
bool visit[2501];
// 1 + 2 - 3 *

long long cal(pair<long long, long long> p, int o) {
	long long f = p.first;
	long long s = p.second;
	if (o == 1) return f + s;
	if (o == 2) return f - s;
	if (o == 3) return f * s;
}

bool bfs(int a) {
	if (visit[a]) return false;

	visit[a] = true;

	for (int i = 1; i <= 3; i++) {
		long long rst = cal(v[a],i);

		auto itr = mp.find(rst);

		if (itr == mp.end()) {
			mp.insert({ rst, a });
			arr[a] = i;
			return true;
		}
		else if (bfs(itr->second)) {
			mp[rst] = a;
			arr[a] = i;
			return true;
		}
	}
	return false;
}

void solve() {

	int cnt = 0;

	for (int i = 0; i < T; i++) {
		memset(visit, false, sizeof(visit));
		if (bfs(i)) cnt++;
	}

	if (cnt != T)
		cout << "impossible";
	else
		for (int i = 0; i < T; i++)
			cout << v[i].first << ' ' << op[arr[i]] << ' ' << v[i].second << " = " << cal(v[i], arr[i]) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	solve();

	return 0;
}