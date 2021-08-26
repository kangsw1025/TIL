#include<iostream>
#include<vector>
using namespace std;

int n,k,cnt;
vector<int> v[51];

void dfs(int st, int rm) {
	if (st == rm) return;

	if (v[st].size() == 0) {
		cnt++;
		return;
	}

	else {
		for (int i = 0; i < v[st].size(); i++) {
			int next = v[st][i];
			if (v[st].size() == 1 && next == rm) cnt++;
			else dfs(next, rm);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int start;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			start = i;
			continue;
		}
		v[num].push_back(i);
	}

	cin >> k;

	dfs(start,k);

	cout << cnt;
	return 0;
}