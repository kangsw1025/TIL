#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int p[1001];
char sx[1001];
bool ch[1001];
priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> q;

int fi(int s) {
	if (p[s] == s) return s;
	else return fi(p[s]);
}

bool check(int n)
{
	for (int i = 2; i <= n; i++)
		if (fi(1) != fi(i))	return false;
	return true;
}

void uni(int s, int d)
{
	if (fi(s) < fi(d)) p[fi(d)] = fi(s);
	else p[fi(s)] = fi(d);
}

bool findP(int s, int d)
{
	if (fi(s) == fi(d)) return 0;
	else return 1;
}

int solve() {
	int ans = 0;
	while (!q.empty()) {
		int p = q.top().first;
		int s = q.top().second.first;
		int d = q.top().second.second;
		q.pop();
		if (sx[s] != sx[d]) {
			if (findP(s, d)) {
				if (ch[s] == false) {
					ch[s] = true;
				}
				if (ch[d] == false) {
					ch[d] = true;
				}
				ans += p;
				uni(s, d);
			}
		}
	}
	if (check(n)) return ans;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> sx[i];
		p[i] = i;
	}
	int s, d, p;
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> p;
		q.push(make_pair(p, make_pair(s, d)));
	}
	cout<<solve();
	return 0;
}