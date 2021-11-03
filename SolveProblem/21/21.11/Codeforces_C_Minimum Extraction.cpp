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
 
long long arr[200001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sort(arr + 1, arr + n + 1);
 
		long long sum = 0, ans = arr[1];
		for (int i = 1; i <= n; i++) {
			arr[i] -= sum;
			sum += arr[i];
			ans = max(ans, arr[i]);
		}
		cout << ans << "\n";
	}
 
	return 0;
}