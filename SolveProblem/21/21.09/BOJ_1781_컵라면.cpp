#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		--v[i].first;
	}

	sort(v.begin(), v.end());

	int result = 0;
	int idx = N - 1;

	priority_queue<int> pq;

	for (int i = N - 1; i >= 0; i--) {
		for (; idx >= 0 && v[idx].first == i; idx--) {
			pq.push(v[idx].second);
		}  if (!pq.empty()) {
			result += pq.top(); pq.pop();
		}
	}
	cout << result << "\n";
	return 0;
}
