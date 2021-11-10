#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> from(n, -1);
		vector<int> how(n, -1);
		vector<int> chk(n, -1);
		queue<int> q;

		q.push(1 % n);
		chk[1 % n] = 0;
		how[1 % n] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == 0) break;

			for (int i = 0; i <= 1; i++) {
				int next = (now * 10 + i) % n;
				if (chk[next] == -1) {
					chk[next] = chk[now] + 1;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}

		if (chk[0] == -1) cout << "BRAK\n";
		else {
			string ans = "";
			for (int i = 0; i != -1; i = from[i]) ans += to_string(how[i]);
			reverse(ans.begin(), ans.end());
			cout << ans << "\n";
		}
	}
	return 0;
}