#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define INF 2e9
int n;
int arr[16][16];
int cache[16][1 << 16];

int solve(int now, int visit) {

	if (visit == (1 << n) - 1) {
		if (arr[now][0] != 0) 
			return arr[now][0];
		return INF;
	}

	int& result = cache[now][visit];
	if (result != -1) return result;

	result = INF;

	for (int next = 0; next < n; next++) {
		if (visit & (1 << next) || arr[now][next] == 0) continue;
		int cd = arr[now][next] + solve(next, visit + (1 << next));
		result = min(result, cd);
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	memset(cache, -1, sizeof(cache));
	cout << solve(0, 1);
	return 0;
}