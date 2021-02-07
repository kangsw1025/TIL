#include<iostream>
#include<cstring>
using namespace std;

int arr[1001];
bool visit[1001], circle[1001];

bool solve(int n) {
	visit[n] = true;
	if (visit[arr[n]]) {
		circle[n] = true;
		return true;
	}
	else if (solve(arr[n])) {
		circle[n] = true;
		return true;
	}

	visit[n] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, cnt = 0;
		cin >> n;
		memset(circle, 0, sizeof(circle));
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++) {
			if (!circle[i])
				if (solve(i))
					cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}