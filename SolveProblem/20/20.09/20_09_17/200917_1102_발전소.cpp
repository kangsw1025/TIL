#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 2e9
int n, p;
string light;
int bit = 1 << 17;
int arr[17][17];
int cache[17][1 << 17];

int countbits(int state) {
	int cnt = 0;
	while (state) {
		cnt += state & 1;
		state >>= 1;
	}
	return cnt;
}

int solve(int idx, int state) {
	if (countbits(state) - 1 >= p) return 0;

	int& rst = cache[idx][state];
	if (rst != -1) return rst;

	rst = INF;
	for (int i = 0; i < n; i++) {
		if ((state & (1 << i)) == 0) {
			int next = state | (1 << i);
			for (int j = 0; j < n; j++) {
				if ((next & (1 << j))) rst = min(rst, arr[idx][i] + solve(j, next));
			}
		}
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	
	cin >> light;
	for (int i = 0; i < light.length(); i++)
		if (light[i] == 'Y') bit |= (1 << i);

	cin >> p;
	if (p == 0) cout << 0;
	else {
		memset(cache, -1, sizeof(cache));
		int result = INF;
		for (int i = 0; i < n; i++)
			if (light[i] == 'Y') result = min(result, solve(i, bit));
		if (result == INF) cout << -1;
		else cout << result;
	}
	return 0;
}
