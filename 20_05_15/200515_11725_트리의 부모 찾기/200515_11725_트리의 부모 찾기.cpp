#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int p[100001];
bool c[100001];
vector<int> vec[100001];

void solve()
{
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); i++) {
			if (c[vec[x][i]] == false) {
				p[vec[x][i]] = x;
				c[vec[x][i]] = true;
				q.push(vec[x][i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,a,b;
	cin >> n;
	c[1] = true;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	solve();
	for (int i = 2; i <= n; i++) cout << p[i] << "\n";
	return 0;
}