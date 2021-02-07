#include<iostream>
#include<cstring>
using namespace std;

typedef struct state{
	int size;
	int speed;
	int intel;
}Jaws;

int n;
Jaws jaws[51];
bool adj[51][51];
int match[51];
int visit[102];
int visitcnt;

bool solve(int a) {
	if (visit[a] == visitcnt) return false;
	visit[a] = visitcnt;
	for (int b = 1; b <= n; b++) {
		if (adj[a][b]) {
			if (!match[b] || solve(match[b])) {
				match[b] = a;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int size, speed, intel;
		cin >> size >> speed >> intel;
		jaws[i].size = size;
		jaws[i].speed = speed;
		jaws[i].intel = intel;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (jaws[i].size == jaws[j].size && jaws[i].speed == jaws[j].speed && jaws[i].intel == jaws[j].intel && i > j)
				continue;
			if (jaws[i].size >= jaws[j].size && jaws[i].speed >= jaws[j].speed && jaws[i].intel >= jaws[j].intel)
				adj[i][j] = 1;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		visitcnt++;
		ans += solve(i);
		visitcnt++;
		ans += solve(i);
	}

	cout << n - ans;
	return 0;
}