#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> v;
	queue<long long> q;

	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
		q.push(i);
	}

	while (!q.empty()) {
		long long now = q.front();
		q.pop();

		for (int i = 0; i < now % 10; i++) {
			long long next = now * 10 + i;
			v.push_back(next);
			q.push(next);
		}
	}

	cout << (n > v.size() ? -1 : v[n - 1]);
	return 0;
}