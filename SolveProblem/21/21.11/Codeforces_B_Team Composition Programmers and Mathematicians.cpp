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
		long long a, b;
		cin >> a >> b;
		if (a >= 3 * b) cout << b << "\n";
		else if (3 * a <= b) cout << a << "\n";
		else {
			int cnt = 0;
			if (a > b) swap(a, b);
			long long diff = (b - a) / 2;
			cnt += min(a, diff);
			a -= min(a, diff);
			b -= min(a, diff) * 3;
			cnt += min(a, b) / 2;
			cout << cnt << "\n";
		}
	}
 
	return 0;
}
