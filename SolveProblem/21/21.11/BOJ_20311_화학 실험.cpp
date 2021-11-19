#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, k;
int color[300001];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;

void solve() {
	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.top().second;
			return;
		}
		else {
			pair<int, int> p1 = q.top();
			q.pop();
			pair<int, int> p2 = q.top();
			q.pop();
			p1.first--;
			p2.first--;
			cout << p1.second << ' ' << p2.second << ' ';
			if(p1.first) q.push(p1);
			if(p2.first) q.push(p2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int mx = 0;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> color[i];
		q.push({ color[i],i });
		mx = max(mx, color[i]);
	}

	if (2 * mx - n >= 2) cout << -1;
	else solve();
	return 0;
}