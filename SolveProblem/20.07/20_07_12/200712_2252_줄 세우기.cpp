#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int arr[32001];
vector<int> vec[32001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[b]++;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		cout << num << ' ';

		for (int i = 0; i < vec[num].size(); i++) {
			arr[vec[num][i]]--;
			if (!arr[vec[num][i]]) q.push(vec[num][i]);
		}
	}

	return 0;
}