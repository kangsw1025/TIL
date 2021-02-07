#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
vector<int> shirt;
vector<int> kara;
vector<int> adj[201];
int match[1001];
int visit[1001];
int visitcnt;

bool solve(int size) {
	if (visit[size] == visitcnt) return false;
	visit[size] = visitcnt;

	for (int sh : adj[size]) {
		if (match[sh] == -1 || solve(match[sh])) {
			match[sh] = size;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		shirt.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		kara.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((shirt[j] * 0.5 <= kara[i] && kara[i] <= shirt[j] * 0.75) || (shirt[j] <= kara[i] && kara[i] <= shirt[j] * 1.25))
				adj[i].push_back(j);
		}
	}

	int ans = 0;

	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i++) {
		visitcnt++;
		if (solve(i)) ans++;
	}

	cout << ans;
	return 0;
}