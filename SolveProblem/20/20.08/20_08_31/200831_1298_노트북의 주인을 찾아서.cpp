#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 101
vector<int> vec[MAX];
int notebook[MAX];
vector<bool> check;

bool solve(int num) {
	for (int i = 0; i < vec[num].size(); i++) {
		int n = vec[num][i];

		if (check[n]) continue;

		check[n] = true;

		if (!notebook[n] || solve(notebook[n])) {
			notebook[n] = num;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		check = vector<bool>(MAX, false);
		if (solve(i)) ans++;
	}
	cout << ans;
	return 0;
}