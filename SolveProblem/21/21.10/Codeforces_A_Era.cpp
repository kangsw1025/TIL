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
		int n,mx = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			int dif = max(0,arr[i] - i);
			mx = max(mx, dif);
		}
		cout << mx << "\n";
	}
 
 
	return 0;
}