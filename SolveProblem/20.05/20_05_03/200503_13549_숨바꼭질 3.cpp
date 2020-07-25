#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int arr[100001];
bool check[100001];

int acc(int num, int c)
{
	if (c == 1) return num * 2;
	else if (c == 2) return num - 1;
	else return num + 1;
}

int bfs(int f, int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, f));

	while (!q.empty()) {
		int c = q.top().first;
		int e = q.top().second;
		q.pop();

		if (e == s) return c;

		for (int i = 1; i <= 3; i++) {
			int nf = acc(e, i);
			if (nf >= 0 && nf <= 100000) {
				if (check[nf] == false) {
					if (i == 1) q.push(make_pair(c, nf));
					else  q.push(make_pair(c + 1, nf));
					check[nf] = true;
				}

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}