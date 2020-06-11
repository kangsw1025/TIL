#include<iostream>
#include<queue>
#include<string>
#include<cmath>
using namespace std;

bool v[10000];

void reset()
{
	for (int i = 0; i < 10000; i++) v[i] = false;
}

int le(int n) {
	return	n % 1000 * 10 + n / 1000;
}

int ri(int n)
{
	return n / 10 + n % 10 * 1000;
}

void solve(int a, int b)
{
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));

	while (!q.empty()) {
		int num = q.front().first;
		string wo = q.front().second;

		q.pop();
		if (num == b) {
			cout << wo << "\n";
			return;
		}

		if (v[num * 2 % 10000] == false) {
			v[num * 2 % 10000] = true;
			q.push(make_pair(num * 2 % 10000, wo + 'D'));
		}
		if (num == 0) {
			if (v[9999] == false) {
				v[9999] = true;
				q.push(make_pair(9999, wo + 'S'));
			}
		}
		else {
			if (v[num - 1] == false) {
				v[num - 1] = true;
				q.push(make_pair(num - 1, wo + 'S'));
			}
		}
		if (v[le(num)] == false) {
			v[le(num)] = true;
			q.push(make_pair(le(num), wo + 'L'));
		}
		if (v[ri(num)] == false) {
			v[ri(num)] = true;
			q.push(make_pair(ri(num), wo + 'R'));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		solve(a, b);
		reset();
	}
	return 0;
}