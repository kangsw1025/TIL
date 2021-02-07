#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int arr[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> w;
set<int> allow;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b,seat = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		w.push(make_pair(a, b));
	}

	while(!w.empty()) {
		while (!q.empty()) {
			if (w.top().first >= q.top().first) {
				allow.insert(q.top().second);
				q.pop();
			}
			else break;
		}

		if (allow.empty()) {
			q.push(make_pair(w.top().second, seat));
			arr[seat]++;
			seat++;
		}

		else {
			auto itr = allow.begin();
			q.push(make_pair(w.top().second, *itr));
			arr[*itr]++;
			allow.erase(itr);
		}
		w.pop();
	}
	cout << seat - 1 << "\n";
	for (int i = 1; i <= seat-1; i++) cout << arr[i] << ' ';
	return 0;
}