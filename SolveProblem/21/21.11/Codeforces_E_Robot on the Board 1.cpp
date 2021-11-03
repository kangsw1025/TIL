#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;

long long arr[200001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;

		int lr = 0, ud = 0, br = 0, bl = 0, bu = 0, bd = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') {
				lr--;
				bl = min(bl, lr);
				if (br - bl >= m) {
					lr++;
					bl++;
					break;
				}
			}
			if (s[i] == 'R') {
				lr++;
				br = max(br, lr);
				if (br - bl >= m) {
					lr--;
					br--;
					break;
				}
			}
			if (s[i] == 'U') {
				ud--;
				bu = min(bu, ud);
				if (bd - bu >= n) {
					ud++;
					bu++;
					break;
				}
			}
			if (s[i] == 'D') {
				ud++;
				bd = max(bd, ud);
				if (bd - bu >= n) {
					ud--;
					bd--;
					break;
				}
			}

		}

		bool print = false;
		for (int i = 1; i <= n; i++) {
			if (i + ud < 1 || i + ud > n || i + bd > n || i + bu < 1) continue;
			for (int j = 1; j <= m; j++)
				if (j + lr >= 1 && j + lr <= m && j + bl >= 1 && j + br <= m) {
					cout << i << ' ' << j << "\n";
					print = true;
					break;
				}
			if (print) break;
		}
	}

	return 0;
}
