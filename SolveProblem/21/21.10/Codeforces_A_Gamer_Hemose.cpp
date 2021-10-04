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
using namespace std;
 
int arr[1001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n, h;
		cin >> n >> h;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + n + 1);
		int cnt = 0, idx = n;
		int sum = arr[n] + arr[n - 1];
 
		cnt += h / sum * 2;
		h %= sum;
		if (h > 0) {
			cnt++;
			h -= arr[n];
		}
		if (h > 0) {
			cnt++;
			h -= arr[n - 1];
		}
		
		cout << cnt << "\n";
	}
 
	return 0;
}