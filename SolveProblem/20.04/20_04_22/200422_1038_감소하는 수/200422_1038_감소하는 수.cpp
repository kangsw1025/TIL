#include <iostream>
#include <queue>
using namespace std;

queue<long long> q;
int num = -1;

void check(int n) {
	if (n <= 9) cout << n;
	else {
		while (1) {
			long long nu = q.front() % 10;
			for (int i = 0; i < nu; i++) {
				q.push(q.front() * 10 + i);
				num++;
				if (num == n) break;
			}
			q.pop();
			if (num == n) break;
			if (n > 1022) {
				cout << -1;
				return;
			}
		}
		cout << q.back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		q.push(i);
		num++;
		if (num == n) break;
	}
	check(n);
	return 0;
}