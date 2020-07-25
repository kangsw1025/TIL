#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int arr[32001];
vector<int> vec[32001];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[b]++;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) if (!arr[i]) q.push(i);

	while (!q.empty()) {
		int x = q.top();
		q.pop();
		cout <<x<<' ';

		for (int i = 0; i < vec[x].size(); i++) {
			arr[vec[x][i]]--;
			if (!arr[vec[x][i]]) q.push(vec[x][i]);
		}
	}
	return 0;
}