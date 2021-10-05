#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int,vector<int>, less<int>> q;

	int n, me, cnt = 0;
	cin >> n >> me;
	for (int i = 1; i < n; i++) {
		int val;
		cin >> val;
		q.push(val);
	}
	while (!q.empty() && q.top() >= me) {
		int val = q.top();
		q.pop();

		q.push(val - 1);
		me++;
		cnt++;
	}

	cout << cnt;
	return 0;
}