#include<iostream>
#include<queue>
using namespace std;

int a, b, n, m;
bool check[100001];

int solve()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, a));
	check[n] = true;
	while (!q.empty()) {
		int t = q.front().first;
		int h = q.front().second;
		q.pop();
		if (h == b) return t;

		if (h - 1 >= 0) {
			if (check[h - 1] == false) {
				q.push(make_pair(t + 1, h - 1));
				check[h - 1] = true;
			}
		}
		if (check[h + 1] == false) {
			q.push(make_pair(t + 1, h + 1));
			check[h + 1] = true;
		}
		if (h + n < 100000) {
			if (check[h + n] == false) {
				q.push(make_pair(t + 1, h + n));
				check[h + n] = true;
			}
		}
		if (h + m < 100000) {
			if (check[h + m] == false) {
				q.push(make_pair(t + 1, h + m));
				check[h + m] = true;
			}
		}if (h - n >= 0) {
			if (check[h - n] == false) {
				q.push(make_pair(t + 1, h - n));
				check[h - n] = true;
			}
		}if (h - m >= 0) {
			if (check[h - m] == false) {
				q.push(make_pair(t + 1, h - m));
				check[h - m] = true;
			}
		}if (h * n < 100000) {
			if (check[h * n] == false) {
				q.push(make_pair(t + 1, h * n));
				check[h * n] = true;
			}
		}if (h * m < 100000) {
			if (check[h * m] == false) {
				q.push(make_pair(t + 1, h * m));
				check[h * m] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a >> b;
	cout << solve();
	return 0;
}