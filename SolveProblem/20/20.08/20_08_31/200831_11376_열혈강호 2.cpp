#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 2001

int n, m;
vector<int> work[MAX];
int ker2k[MAX], k2ker[MAX];
bool check[MAX];

bool solve(int w) {
	for (int i = 0; i < work[w].size();i++) {
		int worknum = work[w][i];
		if (check[worknum]) continue;

		check[worknum] = true;

		if (k2ker[worknum] == -1 || solve(k2ker[worknum])) {
			ker2k[w] = worknum;
			k2ker[worknum] = w;

			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;

			work[i * 2].push_back(num - 1);
			work[i * 2 + 1].push_back(num - 1);
		}
	}

	memset(ker2k, -1, sizeof(ker2k));
	memset(k2ker, -1, sizeof(k2ker));

	int ans = 0;

	for (int i = 0; i < n * 2; i++) {
		if (ker2k[i] == -1) {
			memset(check, false, sizeof(check));
			if (solve(i)) ans++;
		}
	}
	cout << ans;
	return 0;
}