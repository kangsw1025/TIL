#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[51];
int arr[51], ans[51], cnt[51];
bool c[51];
int p, anw = 100;

void reset(int n)
{
	for (int i = 1; i <= n; i++) {
		arr[i] = 0;
		c[i] = false;
	}
}

void solve(int n)
{
	int sum = 0;
	queue<int> q;
	q.push(n);
	c[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int w = v[x][i];
			if (c[w] == false) {
				c[w] = true;
				arr[w] = arr[x] + 1;
				sum = max(sum, arr[w]);
				q.push(w);
			}
		}
	}
	cnt[sum]++;
	ans[n] = sum;
	anw = min(anw, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p;
	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= p; i++) {
		solve(i);
		reset(p);
	}

	cout << anw << ' ' << cnt[anw] << "\n";
	for (int i = 1; i <= p; i++)
		if (ans[i] == anw) cout << i << ' ';
	return 0;
}