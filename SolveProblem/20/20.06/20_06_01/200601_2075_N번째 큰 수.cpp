#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, less<int> > q;
	int n, m, size = 0;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> m;
		if (size < n) {
			q.push(-m);
			size++;
		}
		else {
			if (-q.top() < m) {
				q.pop();
				q.push(-m);
			}
		}
	}
	cout << -q.top();
	return 0;
}