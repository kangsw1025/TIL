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
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
 
	while (T--) {
		int n, k;
		vector<int> v;
 
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			int val;
			cin >> val;
			v.push_back(n - val);
		}
 
		sort(v.begin(), v.end());
 
		int ans = 0;
		long long sum = 0;
 
		for (int i = 0; i < k; i++) {
			int x = v[i];
			if (sum + x < n) {
				ans++;
				sum += x;
			}
			else break;
		}
		cout << ans << "\n";
	}
	return 0;
}