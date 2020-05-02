#include<iostream>
#include<queue>
using namespace std;

int n, k;
int arr[100001];
bool check[100001];
int ans, cnt = -1;

int acc(int num, int c)
{
	if (c == 1) return num * 2;
	else if (c == 2) return num - 1;
	else return num + 1;
}

void bfs(int f, int s)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, f));
	check[f] = true;

	while (!q.empty()) {
		int c = q.front().first;
		int e = q.front().second;
		q.pop();
		check[e] = true;

		if (e == s) {
			if (cnt == -1) {
				cnt = c;
				ans++;
			}
			else {
				if (c == cnt) ans++;
			}
		}
		else
			for (int i = 1; i <= 3; i++) {
				int nf = acc(e, i);
				if (nf >= 0 && nf <= 100000) {
					if (check[nf] == false) {
						q.push(make_pair(c + 1, nf));
					}
				}
			}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	bfs(n, k);
	cout << cnt << "\n" << ans;
	return 0;
}