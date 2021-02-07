#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int n, m;
vector<int> v;
int visit[8], numCnt[10001];

void solve(int idx, int start, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) 
			cout << v[visit[i]] << ' ';
		cout << "\n";
		return;
	}
	if (idx == n) return;

	for (int i = start; i < v.size(); i++) {
		if (numCnt[v[i]]) {
			numCnt[v[i]]--;
			visit[idx] = i;
			solve(idx + 1, i, cnt + 1);
			numCnt[v[i]]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (!numCnt[num]) {
			numCnt[num] = 1;
			v.push_back(num);
		}
		else {
			numCnt[num]++;
		}
	}
	sort(v.begin(), v.end());
	
	solve(0, 0, 0);

	return 0;
}