#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> q;

	int n,num;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);
	}

	while (!(q.size() == 1)) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	cout << ans;
	return 0;
}