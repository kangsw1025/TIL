#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define Max 301

int x, y, n, A[Max], B[Max];
bool visit[Max], isblock[Max][Max];
vector<int> graph[Max];

bool dfs(int k) {
	visit[k] = true;

	for (auto& h : graph[k]) {
		if (B[h] == -1 || (!visit[B[h]] && dfs(B[h]))) {
			A[k] = h;
			B[h] = k;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> n;

	fill(A, A + Max, -1);
	fill(B, B + Max, -1);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		isblock[a][b] = true;
	}

	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			if (!isblock[i][j]) graph[i].push_back(j);

	int ans = 0;
	for (int i = 1; i <= x; i++) {
		if (A[i] == -1) {
			fill(visit, visit + Max, false);
			if (dfs(i)) ans++;
		}
	}
	cout << ans;
	return 0;
}