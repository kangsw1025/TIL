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
#include<cstdlib>
using namespace std;
 
 
int solve(int u, int v) {
	if (u == 0 || v == 0) return 0;
	if (u == 2 && v == 2) return 2;
	int w, h;
 
	if (u < 3) w = v;
	else w = (u / 3) * v + solve(u % 3, v);
	if (v < 3) h = u;
	else h = (v / 3) * u + solve(u, v % 3);
 
	return min(w,h);
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int u, v;
		cin >> u >> v;
 
		if (u % 3 == 0) {
			cout << u / 3 * v << "\n";
		}
		else if (v % 3 == 0) {
			cout << v / 3 * u << "\n";
		}
		else {
			cout << solve(u, v)<<"\n";
		}
	}
 
	return 0;
}