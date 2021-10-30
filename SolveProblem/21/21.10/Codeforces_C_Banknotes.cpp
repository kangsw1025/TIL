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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		vector<long long> v, diff;
		long long n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			long long val;
			cin >> val;
			v.push_back(val);
		}
 
 
		if (n == 1) cout << k + 1 << "\n";
		else {
			long long ans = 0;
			k++;
			for (int i = 1; i < n; i++)
				diff.push_back(v[i] - v[i - 1]);
 
			for (int i = 0; i < diff.size() && k; i++) {
				long long cnt = min(k, (long long)(pow(10, diff[i])-1LL));
				k -= cnt;
				ans += (long long)(pow(10,v[i])) * cnt;
			}
 
			if (k) ans += (long long)(pow(10,v[v.size() - 1])) * k;
			cout << ans<<"\n";
		}
	}
 
	return 0;
}