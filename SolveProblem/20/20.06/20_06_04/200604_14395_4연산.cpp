#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;

map<long long, int> mp;

void solve(int s, int d)
{
	if (s == d) {
		cout << 0;
		return;
	}

	if (d == 0) {
		cout << '-';
		return;
	}

	mp[s] = 1;
	queue<pair<string, long long>> q;
	q.push(make_pair("", s));
	while (!q.empty()) {
		string wo = q.front().first;
		long long n = q.front().second;
		q.pop();

		if (n == d) {
			cout << wo;
			return;
		}

		if (d >= n * n && n != 1 && !mp[n * n]) {
			mp[n * n] = 1;
			q.push(make_pair(wo + "*", n * n));
		}
		if (d >= n * 2 && n != 2 && !mp[n * 2]) {
			mp[n * 2] = 1;
			q.push(make_pair(wo + "+", n * 2));
		}
		if (!mp[1]) {
			mp[1] = 1;
			q.push(make_pair("/", 1));
		}

	}

	cout << -1;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, d;
	cin >> s >> d;
	solve(s, d);
	return 0;
}