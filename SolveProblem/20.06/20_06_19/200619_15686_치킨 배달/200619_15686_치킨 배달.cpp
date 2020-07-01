#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define INF 987654231
vector<pair<int, int>> p, ch;
int n, m, ans = INF;
bool on[14];
int arr[51][51];

int find(pair<int, int> pa) {
	int sum = INF;
	int w = pa.first;
	int h = pa.second;

	for (int i = 0; i < 14; i++) {
		if (on[i] == true) {
			int chi = abs(ch[i].first - w) + abs(ch[i].second - h);
			sum = min(sum, chi);
		}
	}
	return sum;
}

void go(int now, int cnt) {
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < p.size(); i++) {
			sum += find(p[i]);
		}
		if (ans > sum) ans = sum;
		return;
	}

	for (int i = now; i < ch.size(); i++) {
		on[i] = true;
		go(i + 1, cnt + 1);
		on[i] = false;
	}

}

void solve() {
	for (int i = 0; i < ch.size(); i++) {
		on[i] = true;
		go(i+1, 1);
		on[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)	p.push_back(make_pair(i, j));
			if (arr[i][j] == 2) ch.push_back(make_pair(i, j));
		}
	}
	solve();
	cout << ans;
	return 0;
}
