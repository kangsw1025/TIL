#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool arr[20001];
int a[10001], b[10001];
bool visit[10001];
vector<int> av[10001];

void init() {
	for (int i = 2; i <= 20000; i *= 2)
		arr[i] = true;
}

bool solve(int q) {
	if (visit[q]) return false;

	visit[q] = true;

	for (int i = 0; i < av[q].size(); i++) {
		int n = av[q][i];

		if (b[n] == 0 || solve(b[n])) {
			a[q] = n;
			b[n] = q;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (arr[i + j]) av[i].push_back(j);

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		solve(i);
	}

	for (int i = 1; i <= n; i++) cout << a[i] << "\n";
	return 0;
}