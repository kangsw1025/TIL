#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int n, m;
vector<int> vec[1001];
bool visit[1001];
int idol[1001];
map<string, int> match;

bool solve(int num) {
	if (visit[num]) return false;
	visit[num] = true;

	for (int i = 0; i < vec[num].size(); i++) {
		int peo = vec[num][i];

		if (!idol[peo] || solve(idol[peo])) {
			idol[peo] = num;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string name;
		cin >> name;
		match.insert({ name,i });
	}
	
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for(int j=0;j<t;j++) {
			string name;
			cin >> name;
			vec[i].push_back(match[name]);
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (solve(i)) ans++;
	}

	if (ans == n) cout << "YES";
	else cout << "NO\n" << ans;

	return 0;
}