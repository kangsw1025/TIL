#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int bmatch[501];
bool visit[501];
vector<pair<int, pair<string, string>>> male, female;

bool dfs(int a) {
	if (visit[a]) return false;
	visit[a] = true;

	int h1 = male[a].first;
	string m1 = male[a].second.first;
	string s1 = male[a].second.second;

	for (int i = 0; i < female.size(); i++) {
		int h2 = female[i].first;
		string m2 = female[i].second.first;
		string s2 = female[i].second.second;

		if (abs(h2 - h1) <= 40 && m1 == m2 && s1 != s2) {
			if (bmatch[i] == -1 || dfs(bmatch[i])) {
				bmatch[i] = a;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		memset(bmatch, -1, sizeof(bmatch));

		male.resize(0);
		female.resize(0);

		for (int i = 0; i < n; i++) {
			int h;
			char s;
			string music, sport;

			cin >> h >> s >> music >> sport;
			if (s == 'M') male.push_back({ h,{music,sport} });
			if (s == 'F') female.push_back({ h,{music,sport} });
		}

		int cnt = 0;

		for (int i = 0; i < male.size(); i++) {
			memset(visit, false, sizeof(visit));

			if (dfs(i)) cnt++;
		}

		cout << n - cnt << "\n";
	}
	return 0;
}