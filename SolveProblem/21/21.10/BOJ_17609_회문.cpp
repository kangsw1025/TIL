#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int i = 0, j = s.length() - 1;

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
		q.push({ 0,{i,j} });

		while (!q.empty()) {
			int status = q.top().first;
			int l = q.top().second.first;
			int r = q.top().second.second;
			q.pop();

			if (l > r || status >= 2) {
				cout << min(status, 2) << "\n";
				break;
			}

			if (s[l] == s[r]) {
				q.push({ status,{l+1,r-1} });
			}
			else {
				bool pushed = false;
				if (s[l + 1] == s[r] && l + 1 <= r) {
					if (status == 0) {
						pushed = true;
						q.push({ 1,{l + 2,r - 1} });
					}
				}
				if (s[l] == s[r - 1] && l <= r - 1) {
					if (status == 0) {
						pushed = true;
						q.push({ 1,{l + 1,r - 2} });
					}
				}
				if (!pushed) {
					q.push({ 2,{l + 1,r - 1} });
				}
			}
		}

	}
	return 0;
}