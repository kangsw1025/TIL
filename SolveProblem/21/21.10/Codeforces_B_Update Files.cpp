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
		long long n, k;
		cin >> n >> k;
		long long cnt = 0, now = 1;
		while (now < n && now < k) {
			cnt++;
			now *= 2;
		}
 
		if (now >= n) {
			cout << cnt << "\n";
			continue;
		}
 
		long long diff = n - now;
		cnt += diff / k;
		if (diff % k) cnt++;
 
		cout << cnt << "\n";
	}
 
	return 0;
}