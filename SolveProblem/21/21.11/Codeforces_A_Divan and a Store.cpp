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
 
int arr[101];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n, l, r, k, ans = 0;
		cin >> n >> l >> r >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			if (arr[i] >= l && arr[i] <= r) {
				if (k - arr[i] >= 0) {
					k -= arr[i];
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
 
	return 0;
}