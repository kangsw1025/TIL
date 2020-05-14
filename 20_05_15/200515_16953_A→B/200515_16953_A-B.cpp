#include<iostream>
#include<vector>
#include<queue>
#include<vector>
using namespace std;

int a;
long long b;

int solve()
{
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
	q.push(make_pair(0, a));

	while (!q.empty()) {
		long long n = q.top().second;
		int c = q.top().first;
		q.pop();
		
		if (n == b) return c + 1;

		if (n * 2 <= b) q.push(make_pair(c + 1, 2 * n));
		if (n * 10 + 1 <= b) q.push(make_pair(c + 1, n * 10 + 1));

	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	cout<<solve();

	return 0;
}