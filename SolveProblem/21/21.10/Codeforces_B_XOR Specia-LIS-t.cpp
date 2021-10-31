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
 
int arr[100001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		bool on = false;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] <= arr[i - 1]) on = true;
		}
 
		if (n % 2 == 0) cout << "YES\n";
		else {
			if (on) cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
 
	return 0;
}