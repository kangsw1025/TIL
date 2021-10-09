#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
using namespace std;

int n, x, y;
string a, b;
char fin[2];


int solve(int idx, int finger) {
	if (idx + finger == n) return 1;

	if (a[idx] == b[idx + finger])
		if (solve(idx + 1, finger)) return 1;

	if (finger==2) return 0;

	if (fin[finger] == b[idx + finger])
		if (solve(idx, finger + 1)) return 1;

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> a >> b;

	cin >> x >> y;
	fin[0] = a[x];
	fin[1] = a[y];

	int t = 0;
	for (int i = 0; i < n; i++) {
		if (i == x || i == y) continue;
		a[t] = a[i];
		t++;
	}

	if (solve(0, 0)) cout << "YES";
	else cout << "NO";

	return 0;
}