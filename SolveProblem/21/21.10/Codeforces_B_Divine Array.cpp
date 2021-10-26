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
 
int n, q;
int cnt[2001][10001], c[2001];
 
int init() {
	for (int t = 1;; t++) {
		bool change = false;
 
		memset(c, 0, sizeof(c));
 
		for (int i = 1; i <= n; i++)
			c[cnt[i][t-1]]++;
		
		for (int i = 1; i <= n; i++) {
			int val = cnt[i][t-1];
			int ct = c[val];
			if (ct != val) change = true;
			cnt[i][t] = ct;
		}
 
		if (!change) return t;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			cin >> cnt[i][0];
		}
 
		int idx = init();
 
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int a, b;
			cin >> a >> b;
			
			cout << cnt[a][min(b,idx)]<<"\n";
		}
	}
	
 
	return 0;
}